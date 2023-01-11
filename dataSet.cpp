#include "dataSet.h"
#include "batch.h"
#include "fileManager.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>

DataSet::DataSet(std::string fileName) {
	fileManager.initialize(fileName);
	std::vector<int> vec = fileManager.getInitialVals();
	numBatches = vec.at(0);
	numItems = vec.at(1);
	percBadBatches = vec.at(2);
	percBadItems = vec.at(3);
	sampledItems = vec.at(4);
	createBatches();
	fillBatches();
}

void DataSet::createBatches() {
	for (int i = 0; i < numBatches; ++i) {
		std::stringstream ss;
		ss << "ds";
		ss << i + 1;
		ss << ".txt";
		std::string batchName = ss.str();
		Batch temp(fileManager, batchName);
		batches.push_back(temp);
	}
}

void DataSet::fillBatches() {
	minBad = INT_MAX;
	maxBad = 0;
	avgBad = 0;
	int numBad = numBatches * (percBadBatches * .01);
	int numGood = numBatches - numBad;
	for (int i = 0; i < numBad; ++i) {
		int badPlaced = batches.at(i).fillBad(fileManager, numItems, percBadItems);
		if (badPlaced > maxBad) {
			maxBad = badPlaced;
		}
		if (badPlaced < minBad) {
			minBad = badPlaced;
		}
		avgBad += badPlaced;
	}
	for (int i = numBad; i < numGood + numBad; ++i) {
		batches.at(i).fillGood(fileManager, numItems);
	}
	avgBad /= numBad;
}

bool DataSet::testBatch(Batch batch, int numToRead) {
	return batch.testIfGood(fileManager, numToRead);
}

std::vector<Batch> DataSet::getBatches() {
	return batches;
}

int DataSet::getNumBatches() {
	return numBatches;
}

int DataSet::getNumItems() {
	return numItems;
}

int DataSet::getPercBadBatches() {
	return percBadBatches;
}

int DataSet::getPercBadItems() {
	return percBadItems;
}

int DataSet::getSampledItems() {
	return sampledItems;
}

int DataSet::getMaxBad() {
	return maxBad;
}

int DataSet::getMinBad() {
	return minBad;
}

int DataSet::getAvgBad() {
	return avgBad;
}