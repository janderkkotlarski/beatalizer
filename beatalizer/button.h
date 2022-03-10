#ifndef BUTTON_H
#define BUTTON_H

#include <vector>

#include "raylib.h"

enum class boardkey
{
  exit, restart, visible,
  bpm_plus, bpm_minus,
  up2front, front2up, right2front, front2right,
  up2right, right2up, zoom_in, zoom_out,
  none
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

  const Color m_color
  { 0, 0, 0, 0 };

public:
  button(const boardkey board, const int window_size);

  void icon();

  void display() const;

  boardkey pressed_key() const noexcept;
};

std::vector <button> knobverse(const int window_size);

void knobsplay(std::vector <button> &knobs);

std::vector <boardkey> pressed_keys(const std::vector <button> &knobs);

bool keypressed(const std::vector <boardkey> &keys_pressed, const boardkey accept_key);

boardkey int2board(const int number) noexcept;

KeyboardKey board2key(const boardkey board) noexcept;

Vector2 board2xy(const boardkey board) noexcept;

Color board2color(const boardkey board) noexcept;



#endif // BUTTON_H
