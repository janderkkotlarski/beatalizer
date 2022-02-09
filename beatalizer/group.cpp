#include "group.h"

group::group(auronacci &gold)
  : m_cubes(form_random_arc(m_amount, gold))
{

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
