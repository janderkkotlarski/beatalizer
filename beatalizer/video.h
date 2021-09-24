#ifndef VIDEO_H
#define VIDEO_H

#include <chrono>
#include <thread>

#include "raylib.h"

class video
{
private:
  const int m_screen_width
  { 800 };

  const int m_screen_height
  { 800 };

  const int m_fps
  { 1000 };

  const Vector3 m_anchor
  { 0.0f, 0.0f, 0.0f };

  Vector3 m_front_norm
  { 1.0f, 0.0f, 0.0f };

  Vector3 m_right_norm
  { 0.0f, 1.0f, 0.0f };

  Vector3 m_up_norm
  { 0.0f, 0.0f, 1.0f };

  float m_dist
  { 16.0f };

  const float m_rotation_speed
  { 0.03f };

  const float m_multiply
  { 1.01f };

  Camera m_camera;

  Shader m_lighting_shader;

  float m_bps
  { 2.0f };

  const int m_division
  { 1000000000/1024 };

  std::chrono::steady_clock::time_point m_now;
  std::chrono::steady_clock::time_point m_then;

  std::chrono::steady_clock::duration m_period;

  std::chrono::steady_clock::duration m_rest;


  std::chrono::steady_clock::duration m_divider
  { m_division };

  std::chrono::microseconds m_tick
  { static_cast<int>(m_division/m_bps) };


public:
  video();

  void initialize();

  void update_cam();

  void rotate(Vector3 &from, Vector3 &toward);

  void rotate_cam();

  void run();
};

float to_seconds(const int period)
noexcept;

#endif // VIDEO_H
