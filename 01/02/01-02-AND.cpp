#include <format>
#include <iostream>

#include "AND.h"

using namespace std;

int main()
{
	cout << format("AND(0, 0) = {}", AND(0.0, 0.0)) << endl;
	cout << format("AND(0, 1) = {}", AND(0.0, 1.0)) << endl;
	cout << format("AND(1, 0) = {}", AND(1.0, 0.0)) << endl;
	cout << format("AND(1, 1) = {}", AND(1.0, 1.0)) << endl;

	return 0;
}
