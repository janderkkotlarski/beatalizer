#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"

enum class boardkey
{
  exit, restart, visible,
  bpm_plus, bpm_minus,
  up2front, front2up, right2front, front2right,
  up2right, right2up, zoom_in, zoom_out
};

class button
{
private:
  const KeyboardKey m_key
  { KeyboardKey::KEY_KP_0 };

  const Vector2 m_xy
  { 0.0f, 0.0f };

  const float m_size
  { 0.0f };

public:
  button();
};



#endif // BUTTON_H
