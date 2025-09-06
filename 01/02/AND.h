#ifndef AND_H_INCLUDED
#define AND_H_INCLUDED

#include <concepts>

template <std::floating_point T>
T AND(T x1, T x2)
{
	constexpr T w1 = static_cast<T>(0.5);
	constexpr T w2 = static_cast<T>(0.5);
	constexpr T theta = static_cast<T>(0.7);

	T tmp = x1 * w1 + x2 * w2;
	return (tmp <= theta) ? static_cast<T>(0) : static_cast<T>(1);
}

#endif // AND_H_INCLUDED
