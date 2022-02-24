#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"

enum class boardkey
{
  none, exit, restart, visible,
  bpm_plus, bpm_minus,
  up2front, front2up, right2front, front2right,
  up2right, right2up, zoom_in, zoom_out
};

class button
{
private:
  const boardkey m_board
  { boardkey::none };

  const KeyboardKey m_key
  { KeyboardKey::KEY_KP_0 };

  const float m_screen
  { 0.0f };

  const Vector2 m_xy
  { 0.0f, 0.0f };

  const float m_mult
  { 0.05f };

  const float m_size
  { 0.0f };

public:
  button(const boardkey board, const int window_size);

  void display();
};

KeyboardKey board2key(const boardkey board) noexcept;

Vector2 board2xy(const boardkey board) noexcept;

#endif // BUTTON_H
