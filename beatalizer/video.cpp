 #include "video.h"

#include <string>
#include <cmath>
#include <vector>
#include <iostream>

#include "form.h"
#include "group.h"
#include "functions.h"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_RPI, PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif

#define RLIGHTS_IMPLEMENTATION
#include "rlights.h"
#include "raymath.h"

video::video()
{
}

void video::initialize()
{
  SetConfigFlags(FLAG_MSAA_4X_HINT);  // Enable Multi Sampling Anti Aliasing 4x (if available)
  InitWindow(m_screen_width, m_screen_height, "beatalizer");

  SetTargetFPS(m_fps);
  update_cam();
  m_camera.fovy = 45.0f;                                // Camera field-of-view Y
  m_camera.type = CAMERA_PERSPECTIVE;                  // Camera mode type

  m_lighting_shader = LoadShader("base_lighting.vs", "lighting.fs");
  // LoadShader("base_lighting.vs", "lighting.fs");

  m_lighting_shader.locs[LOC_MATRIX_MODEL] =
      GetShaderLocation(m_lighting_shader, "matModel");
  m_lighting_shader.locs[LOC_VECTOR_VIEW] =
      GetShaderLocation(m_lighting_shader, "viewPos");
}

void video::rebeat()
{ m_micros_per_beat = m_million*m_minute/m_bpm; }

void video::update_cam()
{
  m_camera.position = Vector3Scale(m_front_norm, m_dist);    // Camera position
  m_camera.target = m_anchor;      // Camera looking at point
  m_camera.up = m_up_norm;          // Camera up vector (rotation towards target)

  UpdateCamera(&m_camera);
}

void video::rotate(Vector3 &from, Vector3 &toward)
{
  const Vector3 new_from
  { Vector3Add(Vector3Scale(from, cos(m_rotation_speed)),
               Vector3Scale(toward, -sin(m_rotation_speed)))};

  const Vector3 new_toward
  { Vector3Add(Vector3Scale(from, sin(m_rotation_speed)),
               Vector3Scale(toward, cos(m_rotation_speed)))};

  from = Vector3Normalize(new_from);

  toward = Vector3Normalize(new_toward);
}

void video::rotate_cam()
{
  if (IsKeyDown(KEY_W))
  { rotate(m_up_norm, m_front_norm); }

  if (IsKeyDown(KEY_S))
  { rotate(m_front_norm, m_up_norm); }

  if (IsKeyDown(KEY_D))
  { rotate(m_right_norm, m_front_norm); }

  if (IsKeyDown(KEY_A))
  { rotate(m_front_norm, m_right_norm); }

  if (IsKeyDown(KEY_L))
  { rotate(m_up_norm, m_right_norm); }

  if (IsKeyDown(KEY_J))
  { rotate(m_right_norm, m_up_norm); }

  if (IsKeyDown(KEY_I))
  { m_dist /= m_multiply; }

  if (IsKeyDown(KEY_K))
  { m_dist *= m_multiply; }
}

void video::update_bpm()
{
  if (IsKeyDown(KEY_T))
  {
    m_bpm += m_bpm_delta;

    if (m_bpm > m_bpm_max)
    { m_bpm = m_bpm_max; }

    rebeat();
  }

  if (IsKeyDown(KEY_G))
  {
    m_bpm -= m_bpm_delta;

    if (m_bpm < m_bpm_min)
    { m_bpm = m_bpm_min; }

    rebeat();
  }
}

void video::update_time()
{
  m_micros_then = m_micros_now;
  m_micros_now = micros();
  m_micros_gap = m_micros_now - m_micros_then;

  m_time_gap = float(int(m_micros_gap));

  ++m_counter;
}

void video::run()
{
  SetConfigFlags(FLAG_MSAA_4X_HINT);      // Enable Multi Sampling Anti Aliasing 4x (if available)

  InitWindow(m_screen_width, m_screen_height, "Beatalizer");

  GetFontDefault();

  while (!m_windeath)                // Detect window close button or ESC key
  {
    m_clock.phase_reset();

    const int x_pos
    { int(float(GetScreenHeight())/100.0f) };

    const int font_size
    { 2*x_pos };

    std::vector <group> cube_groups
    { grouping(m_gold) };

    // Main game loop
    update_time();

    m_repeat = true;

    while (m_repeat && !m_windeath)
    {
      if (IsKeyPressed(KEY_SPACE))
      { m_repeat = false; }

      if (IsKeyPressed(KEY_DELETE))
      { m_windeath = true; }

      // Update
      //----------------------------------------------------------------------------------
      rotate_cam();
      update_cam();
      update_bpm();

      BeginDrawing();
      {
        ClearBackground(BLACK);

        update_time();

        m_clock.add_time(m_time_gap, m_micros_per_beat);

        update(cube_groups, m_clock.get_phase(), m_gold);

        BeginMode3D(m_camera);
        {
          display(cube_groups);
        }
        EndMode3D();

        int y_pos
        { x_pos };

        std::string transient;

        /*

        transient = "Phase offset: [" + std::to_string(kube.get_phase_offset()/kube.get_tau()) + "]";
        DrawText(transient.c_str(), x_pos, y_pos, font_size, RED);

        y_pos += font_size;

        transient = "Pos next : [" + std::to_string(kube.get_pos_next().x) + "]["
                                   + std::to_string(kube.get_pos_next().y) + "]["
                                   + std::to_string(kube.get_pos_next().z) + "]";
        DrawText(transient.c_str(), x_pos, y_pos, font_size, RED);

        y_pos += font_size;

        transient = "Jump : [" + std::to_string(kube.get_jump()) + "]";
        DrawText(transient.c_str(), x_pos, y_pos, font_size, RED);
        */
      }

      EndDrawing();

      ++m_frame_counter;
      m_frame_counter %= m_frame_skip;
    }
  }



  CloseWindow();              // Close window and OpenGL context
}


float to_seconds(const int period)
noexcept
{ return static_cast<float>(period)/1000000000.0f; }
