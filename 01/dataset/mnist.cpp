#include <cassert>
#include <bit>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <optional>

#include "mnist.h"

using namespace std;

namespace
{
	struct MnistHeader
	{
		uint32_t magic;
		uint32_t count;
	};

	struct MnistImageHeader : MnistHeader
	{
		uint32_t rows;
		uint32_t cols;
	};

	optional<vector<uint8_t>> LoadImages(const filesystem::path& filePath)
	{
		ifstream fin(filePath, ios::binary);
		if(!fin)
		{
			cerr << "Failed to open file: " << filePath << endl;
			return nullopt;
		}

		MnistImageHeader header;
		if(!fin.read(reinterpret_cast<char*>(&header), sizeof(header)))
		{
			cerr << "Failed to read image header from file: " << filePath << endl;
			return nullopt;
		}

		header.magic = std::byteswap(header.magic);
		header.count = std::byteswap(header.count);
		header.rows = std::byteswap(header.rows);
		header.cols = std::byteswap(header.cols);

		assert(header.magic == 0x00000803);
		assert(header.rows == 28);
		assert(header.cols == 28);

		vector<uint8_t> images(header.count * header.rows * header.cols);
		if(!fin.read(reinterpret_cast<char*>(images.data()), images.size()))
		{
			cerr << "Failed to read image data from file: " << filePath << endl;
			return nullopt;
		}

		return images;
	}

	optional<vector<uint8_t>> LoadLabels(const filesystem::path& filePath)
	{
		ifstream fin(filePath, ios::binary);
		if(!fin)
		{
			cerr << "Failed to open file: " << filePath << endl;
			return nullopt;
		}

		MnistHeader header;
		if(!fin.read(reinterpret_cast<char*>(&header), sizeof(header)))
		{
			cerr << "Failed to read label header from file: " << filePath << endl;
			return nullopt;
		}

		header.magic = std::byteswap(header.magic);
		header.count = std::byteswap(header.count);

		assert(header.magic == 0x00000801);

		vector<uint8_t> labels(header.count);
		if(!fin.read(reinterpret_cast<char*>(labels.data()), labels.size()))
		{
			cerr << "Failed to read label data from file: " << filePath << endl;
			return nullopt;
		}

		return labels;
	}
}

bool Mnist::Initialize(const filesystem::path datasetDirectory)
{
	if
	(
		auto trainImages = LoadImages(datasetDirectory / "train-images.idx3-ubyte");
		trainImages
	)
	{
		mTrainImages = move(*trainImages);
	}
	else
	{
		cerr << "Failed to load training images." << endl;
		return false;
	}


	if
	(
		auto trainLabels = LoadLabels(datasetDirectory / "train-labels.idx1-ubyte");
		trainLabels
	)
	{
		mTrainLabels = move(*trainLabels);
	}
	else
	{
		cerr << "Failed to load training labels." << endl;
		return false;
	}

	assert(mTrainImages.size() == mTrainLabels.size() * 28 * 28);

	if
	(
		auto testImages = LoadImages(datasetDirectory / "t10k-images.idx3-ubyte");
		testImages
	)
	{
		mTestImages = move(*testImages);
	}
	else
	{
		cerr << "Failed to load test images." << endl;
		return false;
	}

	if
	(
		auto testLabels = LoadLabels(datasetDirectory / "t10k-labels.idx1-ubyte");
		testLabels
	)
	{
		mTestLabels = move(*testLabels);
	}
	else
	{
		cerr << "Failed to load test labels." << endl;
		return false;
	}

	assert(mTestImages.size() == mTestLabels.size() * 28 * 28);

	return true;
}
