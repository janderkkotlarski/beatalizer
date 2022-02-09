#ifndef GROUP_H
#define GROUP_H

#include <vector>

#include "form.h"

class group
{
private:
  const int m_amount
  { 8 };

  std::vector <form> m_cubes;
public:
  group(auronacci &gold);

  void set_color();

  void update(const timer &clock, auronacci &gold);

  void display();
};

std::vector <group> grouping(auronacci &gold);

#endif // GROUP_H
