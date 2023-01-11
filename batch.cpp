#include "batch.h"
#include "fileManager.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>

Batch::Batch() {
	//Do nothing
}

Batch::Batch(FileManager& fileManager, std::string fileName) {
	fileManager.createNewFile(fileName);
	this->fileName = fileName;
}

void Batch::fillGood(FileManager& fileManager, int numItems) {
	std::vector<std::string> vec;
	for (int i = 0; i < numItems; ++i) {
		vec.push_back("g");
	}
	fileManager.writeFile(vec, fileName);
}

int Batch::fillBad(FileManager& fileManager, int numItems, int percBad) {
	std::vector<std::string> vec;
	int numBad = 0;
	srand(time(NULL));
	for (int i = 0; i < numItems; ++i) {
		int randNum = rand() % 100 + 1;
		if (randNum <= percBad && randNum >= 1) {
			vec.push_back("b");
			++numBad;
		}
		else {
			vec.push_back("g");
		}
	}
	fileManager.writeFile(vec, fileName);
	return numBad;
}

bool Batch::testIfGood(FileManager& fileManager, int numToRead) {
	bool returnVal = true; // true means batch is good
	std::vector<std::string> fileContent = fileManager.readFile(fileName);
	for (int i = 0; i < numToRead; ++i) {
		if (fileContent.at(i) == "b") {
			returnVal = false;
		}
	}
	return returnVal;
}