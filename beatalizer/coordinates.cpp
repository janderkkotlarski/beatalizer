#include "coordinates.h"

#include <cmath>

#include "timer.h"

coordinates::coordinates()
{

}

Vector3 coordinates::get_pos()
{
  Vector3 pos
  { Vector3Scale(m_unit_x, m_unit_pos.x) };

  pos = Vector3Add(pos, Vector3Scale(m_unit_y, m_unit_pos.y));

  return Vector3Add(pos, Vector3Scale(m_unit_z, m_unit_pos.z));
}

Vector3 coordinates::get_unit_rot()
{
  return m_unit_rot;
}

void coordinates::random_pos_gold(auronacci &gold)
{
  m_unit_pos = random_pos_auro(gold);

  m_unit_dir = random_pos_auro(gold);

  m_unit_rot = Vector3Normalize(Vector3CrossProduct(m_unit_pos, m_unit_dir));

  m_unit_dir = Vector3Normalize(Vector3CrossProduct(m_unit_rot, m_unit_pos));
}

Vector3 random_pos_auro(auronacci &gold)
{
  Vector3 unit_pos;

  const float pos_z
  { 2.0f*gold.get_fraction() - 1.0f };

  const float pos_xy
  { sqrt(1.0f - pos_z*pos_z) };

  const float phi
  { 2.0f*float(M_PI)*gold.get_fraction() };

  unit_pos.x = pos_xy*cos(phi);

  unit_pos.y = pos_xy*sin(phi);

  unit_pos.z = pos_z;

  return unit_pos;
}
