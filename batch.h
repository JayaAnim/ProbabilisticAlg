#ifndef BATCH_H
#define BATCH_H
#include "fileManager.h"
#include <iostream>
#include <string>

class Batch {
private:
	std::string fileName; // filename for batch file
public:
	Batch(); // creates batch object
	Batch(FileManager& fileManager, std::string fileName); // uses filemanager obj to create file of filename
	void fillGood(FileManager& fileManager, int numItems); // uses filemanager obj to fill batch filewith "g"
	int fillBad(FileManager& fileManager, int numItems, int percBad); // uses filemanager obj to fill batchfile with "g" and "b"
	bool testIfGood(FileManager& fileManager, int numToRead); // reads numToRead lines from file and returns true if they contain "b"
};

#endif
