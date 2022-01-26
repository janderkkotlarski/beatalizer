#ifndef PERIOD_H
#define PERIOD_H

#include <string>

#include "auronacci.h"

enum class period
{
  p__64, p__32, p__16, p__8, p__4, p__2,
  p_1, p_2, p_4, p_8, p_16, p_32, p_64, elements
};

int period_size();

period periodic_all(auronacci &gold);

period periodic_low(auronacci &gold);

period periodic_mid(auronacci &gold);

period periodic_high(auronacci &gold);

float period2float(const period &peri);

std::string period2string(const period &peri);

#endif // PERIOD_H
