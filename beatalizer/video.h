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
  { 4.0f, 8.0f, 12.0f };

  Vector3 m_cam_target
  { 0.0f, 0.0f, 0.0f };

  Vector3 m_cam_up
  { 0.0f, 0.0f, 1.0f };

  const float m_cam_speed
  { 0.01 };

  Camera m_camera;

  Shader m_lighting_shader;


public:
  video();

  void initialize();

  void update_cam();

  void move_cam();

  void run();
};

#endif // VIDEO_H
