#include <iostream>
#include <format>
#include "XOR.h"

using namespace std;

int main()
{
	cout << format("XOR(0, 0) = {}", XOR(0.0, 0.0)) << endl;
	cout << format("XOR(0, 1) = {}", XOR(0.0, 1.0)) << endl;
	cout << format("XOR(1, 0) = {}", XOR(1.0, 0.0)) << endl;
	cout << format("XOR(1, 1) = {}", XOR(1.0, 1.0)) << endl;

	return 0;
}
