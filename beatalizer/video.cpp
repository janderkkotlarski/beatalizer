#include "video.h"


#include "raylib.h"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_RPI, PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif

video::video()
{

}

void video::initialize()
{

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
      camera.position = (Vector3){ cam_dist, cam_dist, cam_dist  };
      camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
      camera.up = (Vector3){ 0.0f, 0.0f, 1.0f };
      camera.fovy = 45.0f;
      // camera.projection = CAMERA_PERSPECTIVE;

      Model model = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));
      Model model_2 = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));
      // NOTE: Defining 0 (NULL) for vertex shader forces usage of internal default vertex shader
      // Shader shader = LoadShader(0, TextFormat("resources/shaders/glsl%i/grayscale.fs", GLSL_VERSION));

      // model.materials[0].shader = shader;                     // Set shader effect to 3d model
      // model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture; // Bind texture to model

      Vector3 position = { 0.0f, 0.0f, 0.0f };    // Set model position

      SetCameraMode(camera, CAMERA_PERSPECTIVE);         // Set an orbital camera mode

      SetTargetFPS(60);                           // Set our game to run at 60 frames-per-second
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



                  // DrawModelWires(model, position, 1.0f, WHITE);

                  DrawModel(model_2, position, 1.0f, RED);


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
