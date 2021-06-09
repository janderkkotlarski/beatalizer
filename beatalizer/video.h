#ifndef VIDEO_H
#define VIDEO_H

#include "raylib.h"

class video
{
private:
  const int m_screen_width
  { 800 };

  const int m_screen_height
  { 800 };

  const int m_fps
  { 100 };

  Vector3 m_cam_pos
  { 0.0f, 0.0f, 12.0f };

  Vector3 m_cam_target
  { 0.0f, 0.0f, 0.0f };

  Vector3 m_cam_up
  { 0.0f, 1.0f, 0.0f };

  Camera m_camera;

  Shader m_lighting_shader;


public:
  video();

  void initialize();

  void run();
};

#endif // VIDEO_H
