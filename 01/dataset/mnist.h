#ifndef MNIST_H_INCLUDED
#define MNIST_H_INCLUDED

#include <cstdint>
#include <vector>
#include <filesystem>

class Mnist
{
public:
	bool Initialize(const std::filesystem::path datasetDirectory);
private:
	std::vector<uint8_t> mTrainImages;
	std::vector<uint8_t> mTrainLabels;
	std::vector<uint8_t> mTestImages;
	std::vector<uint8_t> mTestLabels;
};

#endif // MNIST_H_INCLUDED