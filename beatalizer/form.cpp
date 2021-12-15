#include "form.h"

form::form()
{
}

form::form(const float side)
  : m_side_x(side), m_side_y(side), m_side_z(side)
{
}

form::form(const Vector3 &pos)
  : m_pos(pos)
{
}

void form::phasing(const float phase)
{

}

void form::display_cuboid()
{
  DrawCube(m_pos, m_side_x, m_side_y, m_side_z, GREEN);
}
