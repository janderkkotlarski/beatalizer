#include "button.h"

#include <cassert>

#include "raymath.h"

#include "functions.h"

button::button(const boardkey board, const int window_size)
  : m_board(board), m_key(board2key(board)), m_screen(window_size),
    m_xy(Vector2Scale(board2xy(board), m_screen)), m_size(m_mult*m_screen),
    m_color(board2color(board))
{
  assert(board2key(m_board) == m_key);
  assert(m_screen);
  assert(m_size > 0.0f);

}

void button::display() const
{
  const Vector2 pos
  { m_xy.x - 0.5f*m_size, m_xy.y - 0.5f*m_size };

  const Vector2 rect
  { m_size, m_size };

  DrawRectangleV(pos, rect, m_color);
}

std::vector <button> knobverse(const int window_size)
{
  std::vector <button> knobs;

  int counter
  { 0 };

  while (counter > -1)
  {
    knobs.push_back(button(int2board(counter), window_size));

    if (int2board(counter) == boardkey::none)
    { counter = -137; }

    ++counter;
  }

  return knobs;
}

void knobsplay(std::vector <button> &knobs)
{
  for (const button &knob: knobs)
  { knob.display(); }
}

boardkey button::pressed_key() const noexcept
{
  if (IsKeyDown(m_key))
  { return m_board; }

  return boardkey::none;
}

std::vector <boardkey> pressed_keys(const std::vector <button> &knobs)
{
  std::vector <boardkey> p_keys;

  for (const button &knob: knobs)
  {
    if (knob.pressed_key() != boardkey::none)
    { p_keys.push_back(knob.pressed_key()); }
  }

  return p_keys;
}

bool keypressed(const std::vector <boardkey> &keys_pressed, const boardkey accept_key)
{
  for (const boardkey key_press: keys_pressed)
  {
    if (key_press == accept_key)
    { return true; }
  }

  return false;
}

boardkey int2board(const int number) noexcept
{
  switch (number)
  {
    case 0:
      return boardkey::exit;
      break;
    case 1:
      return boardkey::restart;
      break;
    case 2:
      return boardkey::visible;
      break;
    case 3:
      return boardkey::bpm_plus;
      break;
    case 4:
      return boardkey::bpm_minus;
      break;
    case 5:
      return boardkey::up2front;
      break;
    case 6:
      return boardkey::front2up;
      break;
    case 7:
      return boardkey::right2front;
      break;
    case 8:
      return boardkey::front2right;
      break;
    case 9:
      return boardkey::up2right;
      break;
    case 10:
      return boardkey::right2up;
      break;
    case 11:
      return boardkey::zoom_in;
      break;
    case 12:
      return boardkey::zoom_out;
      break;
    case 13:
      return boardkey::none;
      break;
  }

  return boardkey::none;
}

KeyboardKey board2key(const boardkey board) noexcept
{
  switch (board)
  {
    case boardkey::exit:
      return KEY_DELETE;
      break;
    case boardkey::restart:
      return KEY_SPACE;
      break;
    case boardkey::visible:
      return KEY_BACKSPACE;
      break;
    case boardkey::bpm_plus:
      return KEY_T;
      break;
    case boardkey::bpm_minus:
      return KEY_G;
      break;
    case boardkey::up2front:
      return KEY_W;
      break;
    case boardkey::front2up:
      return KEY_S;
      break;
    case boardkey::right2front:
      return KEY_D;
      break;
    case boardkey::front2right:
      return KEY_A;
      break;
    case boardkey::up2right:
      return KEY_E;
      break;
    case boardkey::right2up:
      return KEY_Q;
      break;
    case boardkey::zoom_in:
      return KEY_C;
      break;
    case boardkey::zoom_out:
      return KEY_Z;
      break;
    case boardkey::none:
      return KEY_KP_0;
      break;
  }

  return KEY_KP_0;
}

Vector2 board2xy(const boardkey board) noexcept
{
  switch (board)
  {    
    case boardkey::exit:
      return Vector2{ 0.1f, 0.1f };
      break;
    case boardkey::restart:
      return Vector2{ 0.9f, 0.1f };
      break;
    case boardkey::visible:
      return Vector2{ 0.5f, 0.1f };
      break;
    case boardkey::bpm_plus:
      return Vector2{ 0.1f, 0.7f };
      break;
    case boardkey::bpm_minus:
      return Vector2{ 0.1f, 0.9f };
      break;
    case boardkey::up2front:
      return Vector2{ 0.3f, 0.7f };
      break;
    case boardkey::front2up:
      return Vector2{ 0.3f, 0.9f };
      break;
    case boardkey::right2front:
      return Vector2{ 0.5f, 0.7f };
      break;
    case boardkey::front2right:
      return Vector2{ 0.5f, 0.9f };
      break;
    case boardkey::up2right:
      return Vector2{ 0.7f, 0.7f };
      break;
    case boardkey::right2up:
      return Vector2{ 0.7f, 0.9f };
      break;
    case boardkey::zoom_in:
      return Vector2{ 0.9f, 0.7f };
      break;
    case boardkey::zoom_out:
      return Vector2{ 0.9f, 0.9f };
      break;
    case boardkey::none:
      return Vector2{ -1.0f, -1.0f };
      break;
  }

  return Vector2{ -1.0f, -1.0f };
}

Color board2color(const boardkey board) noexcept
{
  switch (board)
  {
    case boardkey::exit:
      return Color{ 255, 0, 0, 255 };
      break;
    case boardkey::restart:
      return Color{ 255, 255, 0, 255 };
      break;
    case boardkey::visible:
      return Color{ 255, 255, 255, 127 };
      break;
    case boardkey::bpm_plus:
      return Color{ 255, 127, 0, 255 };
      break;
    case boardkey::bpm_minus:
      return Color{ 0, 255, 127, 255 };
      break;
    case boardkey::up2front:
      return Color{ 0, 255, 255, 255 };
      break;
    case boardkey::front2up:
      return Color{ 0, 255, 255, 255 };
      break;
    case boardkey::right2front:
      return Color{ 0, 255, 255, 255 };
      break;
    case boardkey::front2right:
      return Color{ 0, 255, 255, 255 };
      break;
    case boardkey::up2right:
      return Color{ 0, 255, 255, 255 };
      break;
    case boardkey::right2up:
      return Color{ 0, 255, 255, 255 };
      break;
    case boardkey::zoom_in:
      return Color{ 255, 0, 127, 255 };
      break;
    case boardkey::zoom_out:
      return Color{ 127, 0, 255, 255 };
      break;
    case boardkey::none:
    return Color{ 0, 0, 0, 0 };
      break;
  }

  return Color{ 0, 0, 0, 0 };
}


