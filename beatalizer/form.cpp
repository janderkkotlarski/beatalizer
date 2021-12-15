#include "form.h"

#include <cmath>

form::form()
{
}

form::form(const float side)
  : m_side(side), m_side_x(side), m_side_y(side), m_side_z(side)
{
}

form::form(const Vector3 &pos)
  : m_pos(pos)
{
}

void form::phasing(const float phase)
{
  m_pos.y = m_side*sin(phase);

  m_pos.z = 2.0f*m_side*(std::abs(sin(4*phase)) - 0.5f);
}

void form::display_cuboid()
{
  DrawCube(m_pos, m_side_x, m_side_y, m_side_z, GREEN);
}
