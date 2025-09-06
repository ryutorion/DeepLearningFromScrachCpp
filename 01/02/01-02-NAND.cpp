#include <iostream>
#include <format>
#include "NAND.h"

using namespace std;

int main()
{
	cout << format("NAND(0, 0) = {}", NAND(0.0, 0.0)) << endl;
	cout << format("NAND(0, 1) = {}", NAND(0.0, 1.0)) << endl;
	cout << format("NAND(1, 0) = {}", NAND(1.0, 0.0)) << endl;
	cout << format("NAND(1, 1) = {}", NAND(1.0, 1.0)) << endl;

	return 0;
}