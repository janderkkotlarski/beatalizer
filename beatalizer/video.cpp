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
      const int screenWidth = 800;
      const int screenHeight = 800;

      SetConfigFlags(FLAG_MSAA_4X_HINT);      // Enable Multi Sampling Anti Aliasing 4x (if available)

      InitWindow(screenWidth, screenHeight, "testing");

      GetFontDefault();

      m_then = std::chrono::steady_clock::now();

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

              BeginMode3D(m_camera);
              {
                  DrawCube((Vector3){0.0f, 0.0f, 0.0f}, 4.0f, 4.0f, 4.0f, RED);
              }
              EndMode3D();

              m_then = std::chrono::steady_clock::now();
              // When time counting starts

              // m_period = m_rest + m_now - m_then;

              m_period = m_then - m_then;

              while (m_period < m_frame_period)
              {
                m_now = std::chrono::steady_clock::now();
                // Current time counting

                m_period = m_now - m_then;
                // Elapsed time
              }

              const int start_1ms
              { 200000 };

              const int start_2ms
              { 495000 };

              const int start
              { 495000 };

              int end
              { start_1ms };

              const double peri
              { 0.0009 };


              timer tim;

              while (tim.elapsed() < peri)
              {
                ++end;

                int i
                { 0 };

                tim.reset();

                while (i < end)
                { ++i; }
              }

              const double elapsed
              { tim.elapsed() };

              m_thenh = std::chrono::high_resolution_clock::now();
              // When time counting starts




              // m_period = m_rest + m_now - m_then;

              m_periodh = m_thenh - m_thenh;



              while (m_periodh < m_frame_periodh)
              {
                m_nowh = std::chrono::high_resolution_clock::now();
                // Current time counting

                m_periodh = m_nowh - m_thenh;
                // Elapsed time
              }









              // m_then = std::chrono::steady_clock::now();

              // m_now = std::chrono::steady_clock::now();
              // m_period = m_rest + m_now - m_then;

              // m_rest = m_period - m_frame_period;

              // while (m_rest > m_frame_period)
              // { m_rest -= m_frame_period; }

              DrawText(std::to_string(m_periodh.count()).c_str(), 10, 10, 20, GREEN);

              DrawText(std::to_string(m_frame_period.count()).c_str(), 10, 50, 20, YELLOW);

              DrawText(std::to_string(end).c_str(), 10, 90, 20, YELLOW);

              DrawText(std::to_string(elapsed).c_str(), 10, 130, 20, YELLOW);

              // DrawText(std::to_string(m_nowh.time_since_epoch().count()).c_str(), 10, 130, 20, BLUE);

              // DrawText(std::to_string(m_thenh.time_since_epoch().count()).c_str(), 10, 170, 20, BLUE);

              // m_period = m_rest;

          EndDrawing();



          //----------------------------------------------------------------------------------
      }



      CloseWindow();              // Close window and OpenGL context
      //--------------------------------------------------------------------------------------
}


float to_seconds(const int period)
noexcept
{
  return static_cast<float>(period)/1000000000.0f;
}
