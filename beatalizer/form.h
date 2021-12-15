#ifndef FORM_H
#define FORM_H

#include "raylib.h"

class form
{
private:
  Vector3 m_pos
  { 0.0f, 0.0f, 0.0f };

  const float m_side
  { 1.0f };

  float m_side_x
  { 1.0f };

  float m_side_y
  { 1.0f };

  float m_side_z
  { 1.0f };

public:
  form();

  form(const float side);

  form(const Vector3 &pos);

  void phasing(const float phase);

  void display_cuboid();
};

#endif // FORM_H
