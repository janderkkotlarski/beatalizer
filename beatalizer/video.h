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

  const float m_billion
  { 1000000000.0f };

  const float m_thousand24
  { 1024.0f };

  const float m_minute
  { 60.0f };

  float m_bpm
  { 120.0f };

  const float m_fps
  { 60.0f };


  const int m_division
  { int(m_minute*m_billion/(m_bpm*m_thousand24)) };

  std::chrono::high_resolution_clock::time_point m_nowh;

  std::chrono::high_resolution_clock::time_point m_thenh;

  std::chrono::high_resolution_clock::duration m_periodh;

  const std::chrono::high_resolution_clock::duration m_frame_periodh
  { (std::chrono::steady_clock::duration)(int)(m_billion/m_fps) };


  std::chrono::steady_clock::time_point m_now;
  std::chrono::steady_clock::time_point m_then;

  std::chrono::steady_clock::duration m_period
  { 0 };

  std::chrono::steady_clock::duration m_rest
  { (std::chrono::steady_clock::duration)0 };

  const std::chrono::steady_clock::duration m_frame_period
  { (std::chrono::steady_clock::duration)(int)(m_billion/m_fps) };

  std::chrono::steady_clock::duration m_divider
  { m_division };


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
