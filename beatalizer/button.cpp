#include "button.h"

#include <cassert>

#include "raymath.h"

#include "functions.h"

button::button(const boardkey board, const int window_size)
  : m_board(board), m_key(board2key(board)), m_screen(window_size),
    m_xy(Vector2Scale(board2xy(board), m_screen)), m_size(m_mult*m_screen),
    m_color(board2color(board))
{
  assert(m_board != boardkey::none);
  assert(board2key(m_board) == m_key);
  assert(m_screen);
  assert(m_size > 0.0f);
  assert(m_xy.x >= 0.0f);
  assert(m_xy.y >= 0.0f);
  const Color devoid
  { 0, 0, 0, 0 };
  assert(color2ints(m_color) != color2ints(devoid));
}

void button::display()
{
  const Vector2 pos
  { m_xy.x - 0.5f*m_size, m_xy.y - 0.5f*m_size };

  const Vector2 rect
  { m_size, m_size };

  DrawRectangleV(pos, rect, m_color);
}

boardkey button::pressing_key()
{
  if (IsKeyDown(m_key))
  { return m_board; }

  return boardkey::none;
}

KeyboardKey board2key(const boardkey board) noexcept
{
  switch (board)
  {
    case boardkey::none:
      return KEY_KP_0;
      break;
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
  }

  return KEY_KP_0;
}

Vector2 board2xy(const boardkey board) noexcept
{
  switch (board)
  {
    case boardkey::none:
      return Vector2{ -1.0f, -1.0f };
      break;
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
  }

  return Vector2{ -1.0f, -1.0f };
}

Color board2color(const boardkey board) noexcept
{
  switch (board)
  {
    case boardkey::none:
    return Color{ 0, 0, 0, 0 };
      break;
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
      return Color{ 0, 255, 127, 255 };
      break;
    case boardkey::front2up:
      return Color{ 0, 255, 127, 255 };
      break;
    case boardkey::right2front:
      return Color{ 0, 255, 127, 255 };
      break;
    case boardkey::front2right:
      return Color{ 0, 255, 127, 255 };
      break;
    case boardkey::up2right:
      return Color{ 0, 255, 127, 255 };
      break;
    case boardkey::right2up:
      return Color{ 0, 255, 127, 255 };
      break;
    case boardkey::zoom_in:
      return Color{ 255, 0, 127, 255 };
      break;
    case boardkey::zoom_out:
      return Color{ 127, 0, 255, 255 };
      break;
  }

  return Color{ 0, 0, 0, 0 };
}
