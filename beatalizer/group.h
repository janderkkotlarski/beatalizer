#ifndef GROUP_H
#define GROUP_H

#include <vector>

#include "form.h"

class group
{
private:
  const int m_amount
  { 8 };

  const float m_side
  { 0.2f };

  std::vector <form> m_cubes;
public:
  group(auronacci &gold);

  void update(const float phase);

  void display();
};

#endif // GROUP_H
