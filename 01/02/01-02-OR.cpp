#include <iostream>
#include <format>
#include "OR.h"

using namespace std;

int main()
{
	cout << format("OR(0, 0) = {}", OR(0.0, 0.0)) << endl;
	cout << format("OR(0, 1) = {}", OR(0.0, 1.0)) << endl;
	cout << format("OR(1, 0) = {}", OR(1.0, 0.0)) << endl;
	cout << format("OR(1, 1) = {}", OR(1.0, 1.0)) << endl;

	return 0;
}
