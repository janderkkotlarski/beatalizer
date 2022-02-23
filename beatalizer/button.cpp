#include "button.h"

#include <cassert>

button::button(const boardkey board, const int window_size)
  : m_board(board), m_key(board2key(board))
{
  assert(m_board != boardkey::none);
  assert(board2key(m_board) == m_key);
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
