#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

#include "auronacci.h"

enum class period;

enum class trigon;

enum class movement;

enum class dimension;

enum class coloring;

int half_int(const int number);

unsigned char unchar(const float input);

int period_size();

period periodic_all(auronacci &gold);

period periodic_low(auronacci &gold);

period periodic_mid(auronacci &gold);

period periodic_high(auronacci &gold);

std::string period2string(const period &peri);

#endif // FUNCTIONS_H
