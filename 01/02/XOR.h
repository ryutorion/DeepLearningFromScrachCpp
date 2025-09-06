#ifndef XOR_H_INCLUDED
#define XOR_H_INCLUDED

#include <array>
#include <concepts>
#include <numeric>

#include "NAND.h"
#include "OR.h"
#include "AND.h"

template <std::floating_point T>
T XOR(T x1, T x2)
{
	T s1 = NAND(x1, x2);
	T s2 = OR(x1, x2);
	return AND(s1, s2);
}


#endif // XOR_H_INCLUDED