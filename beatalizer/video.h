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

  const Vector3 m_anchor
  { 0.0f, 0.0f, 0.0f };

  Vector3 m_front_norm
  { 1.0f, 0.0f, 0.0f };

  Vector3 m_right_norm
  { 0.0f, 1.0f, 0.0f };

  Vector3 m_up_norm
  { 0.0f, 0.0f, 1.0f };

  float m_dist
  { 8.0f };

  Vector3 m_cam_pos
  { 4.0f, 8.0f, 12.0f };

  Vector3 m_cam_target
  { 0.0f, 0.0f, 0.0f };

  Vector3 m_cam_up
  { 0.0f, 0.0f, 1.0f };

  const float m_rotation_speed
  { 0.03 };

  const float m_cam_speed
  { 0.03 };

  Camera m_camera;

  Shader m_lighting_shader;


public:
  video();

  void initialize();

  void update_cam();

  void move_cam();

  void around_x();

  void rotate_cam();

  void run();
};

#endif // VIDEO_H
