#include "form.h"

form::form()
{
}

form::form(const float side)
  : m_side(side)
{
}

form::form(const Vector3 &pos)
  : m_pos(pos)
{
}

void form::display_cube()
{
  DrawCube(m_pos, m_side, m_side, m_side, GREEN);
}
