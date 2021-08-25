#include "video.h"

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
  m_camera.position = m_cam_pos;    // Camera position
  m_camera.target = m_cam_target;      // Camera looking at point
  m_camera.up = m_cam_up;          // Camera up vector (rotation towards target)
}

void video::move_cam()
{
  if (IsKeyDown(KEY_W))
  {
    m_cam_target.x += m_cam_speed;
    m_cam_pos.x += m_cam_speed;
    // m_cam_up.x += m_cam_speed;
  }

  if (IsKeyDown(KEY_S))
  {
    m_cam_target.x -= m_cam_speed;
    m_cam_pos.x -= m_cam_speed;
    // m_cam_up.x -= m_cam_speed;
  }

  if (IsKeyDown(KEY_D))
  {
    m_cam_target.y += m_cam_speed;
    m_cam_pos.y += m_cam_speed;
    // m_cam_up.y += m_cam_speed;
  }

  if (IsKeyDown(KEY_A))
  {
    m_cam_target.y -= m_cam_speed;
    m_cam_pos.y -= m_cam_speed;
    // m_cam_up.y -= m_cam_speed;
  }

  if (IsKeyDown(KEY_E))
  {
    m_cam_target.z += m_cam_speed;
    m_cam_pos.z += m_cam_speed;
    // m_cam_up.z += m_cam_speed;
  }

  if (IsKeyDown(KEY_Q))
  {
    m_cam_target.z -= m_cam_speed;
    m_cam_pos.z -= m_cam_speed;
    // m_cam_up.z -= m_cam_speed;
  }
}

void video::around_x()
{
  if (IsKeyDown(KEY_L))
  {
    const Vector3 new_right
    { Vector3Add(Vector3Scale(m_right_norm, cos(m_rotation_speed)),
                 Vector3Scale(m_up_norm, sin(m_rotation_speed)))};

    const Vector3 new_up
    { Vector3Add(Vector3Scale(m_right_norm, -sin(m_rotation_speed)),
                 Vector3Scale(m_up_norm, cos(m_rotation_speed)))};

    m_right_norm = Vector3Normalize(new_right);

    m_up_norm = Vector3Normalize(new_up);
  }

  if (IsKeyDown(KEY_J))
  {
    const Vector3 new_right
    { Vector3Add(Vector3Scale(m_right_norm, cos(m_rotation_speed)),
                 Vector3Scale(m_up_norm, -sin(m_rotation_speed)))};

    const Vector3 new_up
    { Vector3Add(Vector3Scale(m_right_norm, sin(m_rotation_speed)),
                 Vector3Scale(m_up_norm, cos(m_rotation_speed)))};

    m_right_norm = Vector3Normalize(new_right);

    m_up_norm = Vector3Normalize(new_up);
  }
}

void video::rotate_cam()
{
  around_x();

}

void video::run()
{
  // Initialization
      //--------------------------------------------------------------------------------------
      const int screenWidth = 800;
      const int screenHeight = 800;

      SetConfigFlags(FLAG_MSAA_4X_HINT);      // Enable Multi Sampling Anti Aliasing 4x (if available)

      InitWindow(screenWidth, screenHeight, "testing");

      SetTargetFPS(100);                           // Set our game to run at 60 frames-per-second
      //--------------------------------------------------------------------------------------

      // Main game loop
      while (!WindowShouldClose())                // Detect window close button or ESC key
      {
          // Update
          //----------------------------------------------------------------------------------
          move_cam();
          update_cam();

          UpdateCamera(&m_camera);                  // Update camera
          //----------------------------------------------------------------------------------

          // Draw
          //----------------------------------------------------------------------------------
          BeginDrawing();

              ClearBackground(BLACK);

              BeginMode3D(m_camera);

                  DrawCube((Vector3){0.0f, 0.0f, 0.0f}, 4.0f, 4.0f, 4.0f, RED);

              EndMode3D();

              DrawFPS(10, 10);

          EndDrawing();
          //----------------------------------------------------------------------------------
      }



      CloseWindow();              // Close window and OpenGL context
      //--------------------------------------------------------------------------------------
}
