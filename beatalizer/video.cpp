#include "video.h"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_RPI, PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif

#define RLIGHTS_IMPLEMENTATION
#include "rlights.h"

video::video()
{

}

void video::initialize()
{

  SetConfigFlags(FLAG_MSAA_4X_HINT);  // Enable Multi Sampling Anti Aliasing 4x (if available)
  InitWindow(m_screen_width, m_screen_height, "beatalizer");

  SetTargetFPS(m_fps);


  m_camera.position = m_cam_pos;    // Camera position
  m_camera.target = m_cam_target;      // Camera looking at point
  m_camera.up = m_cam_up;          // Camera up vector (rotation towards target)
  m_camera.fovy = 45.0f;                                // Camera field-of-view Y
  m_camera.type = CAMERA_PERSPECTIVE;                  // Camera mode type

  m_lighting_shader = LoadShader("base_lighting.vs", "lighting.fs");
  // LoadShader("base_lighting.vs", "lighting.fs");

  m_lighting_shader.locs[LOC_MATRIX_MODEL] =
      GetShaderLocation(m_lighting_shader, "matModel");
  m_lighting_shader.locs[LOC_VECTOR_VIEW] =
      GetShaderLocation(m_lighting_shader, "viewPos");
}

void video::run()
{
  // Initialization
      //--------------------------------------------------------------------------------------
      const int screenWidth = 800;
      const int screenHeight = 800;

      SetConfigFlags(FLAG_MSAA_4X_HINT);      // Enable Multi Sampling Anti Aliasing 4x (if available)

      InitWindow(screenWidth, screenHeight, "raylib [shaders] example - model shader");

      const float cam_dist
      { 8.0f };

      // Define the camera to look into our 3d world
      Camera camera = { 0 };
      camera.position = m_cam_pos;
      camera.target = m_cam_target;
      camera.up = m_cam_up;
      camera.fovy = 45.0f;
      camera.type = CAMERA_PERSPECTIVE;

      Model model = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));
      Model model_2 = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));

      Light light
      { CreateLight(LIGHT_POINT, m_cam_pos, m_cam_target, WHITE, m_lighting_shader) };


      model.materials->shader = m_lighting_shader;

      model_2.materials->shader = m_lighting_shader;
      // NOTE: Defining 0 (NULL) for vertex shader forces usage of internal default vertex shader
      // Shader shader = LoadShader(0, TextFormat("resources/shaders/glsl%i/grayscale.fs", GLSL_VERSION));

      // model.materials[0].shader = shader;                     // Set shader effect to 3d model
      // model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture; // Bind texture to model

      Vector3 position = { 0.0f, 0.0f, 0.0f };    // Set model position

      SetCameraMode(camera, CAMERA_PERSPECTIVE);         // Set an orbital camera mode

      SetTargetFPS(100);                           // Set our game to run at 60 frames-per-second
      //--------------------------------------------------------------------------------------

      // Main game loop
      while (!WindowShouldClose())                // Detect window close button or ESC key
      {
          // Update
          //----------------------------------------------------------------------------------
          UpdateCamera(&camera);                  // Update camera
          //----------------------------------------------------------------------------------

          // Draw
          //----------------------------------------------------------------------------------
          BeginDrawing();

              ClearBackground(BLACK);

              BeginMode3D(camera);



                  DrawModelWires(model, position, 1.0f, BLUE);

                  // DrawModel(model_2, position, 1.0f, RED);


              EndMode3D();

              DrawFPS(10, 10);

          EndDrawing();
          //----------------------------------------------------------------------------------
      }

      // De-Initialization
      //--------------------------------------------------------------------------------------
      // UnloadShader(shader);       // Unload shader
      // UnloadTexture(texture);     // Unload texture
      UnloadModel(model);         // Unload model

      CloseWindow();              // Close window and OpenGL context
      //--------------------------------------------------------------------------------------
}
