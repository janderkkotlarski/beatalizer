#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

#include "auronacci.h"

enum class frequ;

enum class trigon;

enum class movement;

enum class dimension;

enum class coloring;

int half_int(const int number);

unsigned char unchar(const float input);

int frequ_size();

frequ frequify_all(auronacci &gold);

frequ frequify_low(auronacci &gold);

frequ frequify_high(auronacci &gold);

std::string frequ2string(const frequ &freq);

#endif // FUNCTIONS_H
