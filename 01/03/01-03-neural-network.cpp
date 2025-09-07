#include <iostream>
#include "mnist.h"

using namespace std;

int main()
{
	Mnist mnist;
	if(!mnist.Initialize(std::filesystem::path(MNIST_DATASET_PATH)))
	{
		cerr << "Failed to initialize mnist dataset" << endl;
		return -1;
	}
}
