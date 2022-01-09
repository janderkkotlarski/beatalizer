#include "coordinates.h"



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
  const float pos_z
  { 10.0f*gold.get_fraction() - 1.0f };

  const float pos_xy
  { sqrt(1.0f - pos_z*pos_z) };

  const float phi
  { 2.0f*m_pi*gold.get_fraction() };

  m_unit_pos.x = pos_xy*cos(phi);

  m_unit_pos.y = pos_xy*sin(phi);

  m_unit_pos.z = pos_z;
}

