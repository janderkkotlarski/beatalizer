#include "group.h"

#include "coordinates.h"

group::group(auronacci &gold)
  : m_cubes(form_random_arc(m_amount, m_side, gold ))
{
  rephase(gold);
}


void group::update(const float phase, auronacci &gold)
{
  const float delta_phase
  { phase - m_phase_previous };

  m_phase_left -= delta_phase;

  if (m_phase_left < 0.0f)
  {
    rephase(gold);

    const Vector3 dir
    { random_pos_auro(gold) };

    for (form &cube: m_cubes)
    { cube.set_dir(dir); }
  }

  for (form &cube: m_cubes)
  {
    // cube.rephaser(phase, gold);
    cube.orbit();
    cube.set_color();
  }

  m_phase_previous = phase;
}

void group::rephase(auronacci &gold)
{ m_phase_left += period2float(period::p_2); }

void group::display()
{
  for (form &cube: m_cubes)
  { cube.display_cuboid(); }
}
