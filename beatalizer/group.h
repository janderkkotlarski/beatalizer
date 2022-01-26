#ifndef GROUP_H
#define GROUP_H

#include <vector>

#include "form.h"
#include "functions.h"
#include "auronacci.h"
#include "period.h"

class group
{
private:
  const int m_amount
  { 8 };

  const float m_side
  { 0.2f };

  period m_peri
  { period::p_1 };

  float m_phase_left
  { 0.0f };

  float m_phase_previous
  { 0.0f };

  std::vector <form> m_cubes;
public:
  group(auronacci &gold);

  void update(const float phase, auronacci &gold);

  void rephase(auronacci &gold);

  void display();
};

#endif // GROUP_H
