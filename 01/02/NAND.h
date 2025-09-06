#ifndef NAND_H_INCLUDED
#define NAND_H_INCLUDED

#include <array>
#include <concepts>
#include <numeric>

template <std::floating_point T>
T NAND(T x1, T x2)
{
	std::array<T, 2> x = { x1, x2 };
	constexpr std::array<T, 2> weights = { static_cast<T>(-0.5), static_cast<T>(-0.5) };
	constexpr T b = static_cast<T>(0.7);

	T tmp = std::inner_product(x.begin(), x.end(), weights.begin(), T(0)) + b;

	return (tmp <= 0) ? 0 : 1;
}

#endif // NAND_H_INCLUDED