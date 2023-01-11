#include "fileManager.h"
#include "dataSet.h"
#include "batch.h"
#include "analyzer.h"
#include <iostream>
#include <vector>
using namespace std;


int main() {
	vector<string> vec = { "t1.txt", "t2.txt", "t3.txt", "t4.txt" };
	Analyzer createSimulation(vec);
}