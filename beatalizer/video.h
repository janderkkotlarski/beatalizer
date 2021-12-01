#ifndef VIDEO_H
#define VIDEO_H

#include <chrono>
#include <thread>

#include "raylib.h"

class video
{
private:
  int m_screen_width
  { 800 };

  int m_screen_height
  { 800 };

  int m_x_pos
  { 0 };

  int m_font_size
  { 0 };

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

  const float m_million
  { 1000000.0f };

  const float m_2pow10
  { 1024.0f };

  const float m_minute
  { 60.0f };

  float m_bpm
  { 120.0f };

  const float m_fps
  { 60.0f };

  uint64_t m_micros_then
  { 0 };

  uint64_t m_micros_now
  { 0 };

  uint64_t m_micros_gap
  { 0 };

  int m_frame_counter
  { 0 };

  const int m_frame_skip
  { 5 };


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
