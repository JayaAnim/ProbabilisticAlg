#ifndef ANALYZER_H
#define ANALYZER_H
#include "dataSet.h"
#include <iostream>
#include <string>
#include <vector>

class Analyzer {
private:
	int numBatches;
	int numItems;
	int percBadBatches;
	int percBadItems;
	int sampledItems;
	int numBadFound;
	int minBad;
	int maxBad;
	int avgBad;
	int simNum;
public:
	Analyzer(std::vector<std::string> initFileNames);
	void findBadBatches(DataSet& dataset);
	void printResults();
};

#endif
