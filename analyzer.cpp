#include "analyzer.h"
#include "dataSet.h"
#include "batch.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

Analyzer::Analyzer(std::vector<std::string> initFileNames) {
	simNum = 0;
	for (int i = 0; i < initFileNames.size(); ++i) {
		DataSet temp(initFileNames.at(i));
		findBadBatches(temp);
		printResults();
	}
}

void Analyzer::findBadBatches(DataSet& dataset) {
	++simNum;
	std::vector<Batch> batches = dataset.getBatches();
	numBatches = dataset.getNumBatches();
	numItems = dataset.getNumItems();
	percBadBatches = dataset.getPercBadBatches();
	percBadItems = dataset.getPercBadItems();
	sampledItems = dataset.getSampledItems();
	minBad = dataset.getMinBad();
	maxBad = dataset.getMaxBad();
	avgBad = dataset.getAvgBad();
	numBadFound = 0;

	int numBadBatchesFound = 0;
	for (int i = 0; i < numBatches; ++i) {
		if (!dataset.testBatch(batches.at(i), sampledItems)) {
			++numBadFound;
		}
	}
}

void Analyzer::printResults() {
	std::cout << "Simulation #" << simNum << std::endl;
	std::cout << "\tNumber of batches of items: " << numBatches << std::endl;
	std::cout << "\tNumber of items in each batch: " << numItems << std::endl;
	std::cout << "\tPercentage of batches containing bad items: " << percBadBatches << std::endl;
	std::cout << "\tPercentage of items that are bad in a bad set: " << percBadItems << std::endl;
	std::cout << "\tItems sampled from each set: " << sampledItems << std::endl;

	std::cout << "Generating data sets:" << std::endl;
	std::cout << "\tTotal bad sets = " << (numBatches * (.01 * percBadBatches)) << std::endl;
	std::cout << "\tMax number of bad items in a bad set = " << maxBad << std::endl;
	std::cout << "\tMin number of bad items in a bad set = " << minBad << std::endl;
	std::cout << "\tAverage number of bad items in a bad set = " << avgBad << std::endl;
	
	std::cout << "\tAnalyzing Data Sets:" << std::endl;
	std::cout << "\tBase = " << ((100 - percBadItems) * .01) << " exponent = " << sampledItems << std::endl;
	std::cout << "\tP(failure to detect bad item) = " << pow(((100 - percBadItems) * .01), sampledItems) << std::endl;
	std::cout << "\tP(batch is good) = " << 100 - pow(((100 - percBadItems) * .01), sampledItems) << std::endl;
	std::cout << "\tNumber of bad batches found: " << numBadFound << std::endl;
	std::cout << "\tPercentage of bad batches detected = " << (numBadFound / (numBatches * (.01 * percBadBatches))) * 100 << std::endl;
}