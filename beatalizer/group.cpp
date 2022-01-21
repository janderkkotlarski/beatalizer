#include "group.h"

group::group(auronacci &gold)
  : m_cubes(form_random_arc(m_amount, m_side, gold ))
{
}

void group::update(const float phase)
{


  for (form &cube: m_cubes)
  {
    cube.orbit(phase);
    cube.set_color();
  }
}

void group::display()
{
  for (form &cube: m_cubes)
  { cube.display_cuboid(); }
}
