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

void group::update(const float phase, auronacci &gold)
{
  for (form &cube: m_cubes)
  {
    cube.set_phase(phase);
    cube.phasing(gold, m_cubes[0]);
    cube.orbiting();
    cube.transverse();
    cube.longiverse();
    cube.standing_waves();
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
  { 32 };

  std::vector <group> groups;

  for (int count{ 0 }; count < amount; ++count)
  { groups.push_back(group(gold)); }

  return groups;
}

void update(std::vector <group> &cube_groups, const float phase, auronacci &gold)
{
  for (group &cubes: cube_groups)
  { cubes.update(phase, gold); }
}

void display(std::vector <group> &cube_groups)
{
  for (group &cubes: cube_groups)
  { cubes.display(); }
}
