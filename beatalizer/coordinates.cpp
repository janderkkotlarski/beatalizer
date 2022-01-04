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

void coordinates::random_pos()
{
  const int number
  { int(micros()) };

  const float frac_1000
  { float(number % 1000)/1000.0f };

  const float frac_10000
  { float(number % 10000)/10000.0f };

  m_unit_pos.x = cos(frac_1000);

  m_unit_pos.y = sin(frac_1000)*cos(frac_10000);

  m_unit_pos.z = sin(frac_1000)*sin(frac_10000);

}
