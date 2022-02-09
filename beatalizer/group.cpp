#include "group.h"

group::group(auronacci &gold)
  : m_cubes(form_random_arc(m_amount, gold))
{
  set_color();
}

void group::set_color()
{
  for (form &cube: m_cubes)
  { cube.set_color(); }
}

void group::update(const timer &clock, auronacci &gold)
{
  const float phase
  { clock.get_phase() };

  for (form &cube: m_cubes)
  {
    cube.phasing(phase, gold, m_cubes[0]);
    cube.orbiting();
    cube.standing_waves(phase);
    cube.set_color();
  }
}

void group::display()
{
  for (form &cube: m_cubes)
  { cube.display_cuboid(); }
}

std::vector <group> grouping(auronacci &gold)
{
  const int amount
  { 8 };

  std::vector <group> groups;

  for (int count{ 0 }; count < amount; ++count)
  { groups.push_back(group(gold)); }

  return groups;
}
