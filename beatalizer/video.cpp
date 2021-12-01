 #include "video.h"

#include <string>

#include "timer.h"


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

void video::update_cam()
{
  m_camera.position = Vector3Scale(m_front_norm, m_dist);    // Camera position
  m_camera.target = m_anchor;      // Camera looking at point
  m_camera.up = m_up_norm;          // Camera up vector (rotation towards target)
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

void video::run()
{
  // Initialization
      //--------------------------------------------------------------------------------------
      SetConfigFlags(FLAG_MSAA_4X_HINT);      // Enable Multi Sampling Anti Aliasing 4x (if available)

      InitWindow(m_screen_width, m_screen_height, "Beatalizer");

      GetFontDefault();

      const int x_pos
      { int(float(GetScreenHeight())/100.0f) };

      const int font_size
      { 2*x_pos };

      // Main game loop
      while (!WindowShouldClose())                // Detect window close button or ESC key
      {
          // Update
          //----------------------------------------------------------------------------------
          rotate_cam();
          update_cam();

          UpdateCamera(&m_camera);                  // Update camera
          //----------------------------------------------------------------------------------

          // Draw
          //----------------------------------------------------------------------------------
          BeginDrawing();

              ClearBackground(BLACK);

              m_micros_then = m_micros_now;
              m_micros_now = micros();

              if (m_frame_counter == 0)
              { m_micros_gap = m_micros_now - m_micros_then; }

              m_beat_time += float(m_micros_gap);

              BeginMode3D(m_camera);
              {
                  DrawCube((Vector3){0.0f, 0.0f, 0.0f}, 4.0f, 4.0f, 4.0f, RED);
              }
              EndMode3D();

              int y_pos
              { x_pos };

              std::string transient;



              transient = "Period in ns : " + std::to_string(m_micros_gap) + " us";
              DrawText(transient.c_str(), x_pos, y_pos, font_size, RED);

          EndDrawing();

          ++m_frame_counter;
          m_frame_counter %= m_frame_skip;
      }

      CloseWindow();              // Close window and OpenGL context
}


float to_seconds(const int period)
noexcept
{
  return static_cast<float>(period)/1000000000.0f;
}
