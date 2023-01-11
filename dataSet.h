#ifndef DATASET_H
#define DATASET_H
#include "batch.h"
#include "fileManager.h"
#include <iostream>
#include <vector>
#include <string>

class DataSet {
private:
	FileManager fileManager;
	int numBatches;
	int numItems;
	int percBadBatches;
	int percBadItems;
	int sampledItems;
	int maxBad;
	int minBad;
	int avgBad;
	std::vector<Batch> batches;
public:
	DataSet(std::string fileName); 
	void createBatches();
	void fillBatches();
	bool testBatch(Batch batch, int numToRead);
	std::vector<Batch> getBatches();
	int getNumBatches();
	int getNumItems();
	int getPercBadBatches();
	int getPercBadItems();
	int getSampledItems();
	int getMaxBad();
	int getMinBad();
	int getAvgBad();
};

#endif
