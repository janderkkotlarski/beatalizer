#ifndef FORM_H
#define FORM_H

#include "raylib.h"

class form
{
private:
  Vector3 m_pos
  { 0.0f, 0.0f, 0.0f };

  float m_side
  { 1.0f };

public:
  form();

  form(const float side);

  form(const Vector3 &pos);

  void display_cube();
};

#endif // FORM_H
