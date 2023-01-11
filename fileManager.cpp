#include "fileManager.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

FileManager::FileManager() {
	//Do nothing
}

FileManager::FileManager(std::string fileName) {
	std::ifstream inFile;
	inFile.open(fileName);
	if (!inFile.is_open()) {
		std::cout << "Failed to open constructor file: " << fileName << std::endl;
	}
	else {
		while (!inFile.eof()) {
			int temp;
			inFile >> temp;
			initialVals.push_back(temp);
		}
		inFile.close();
		if (inFile.is_open()) {
			std::cout << "Failed to close contructor file: " << fileName << std::endl;
		}
	}
	
}

void FileManager::initialize(std::string fileName) {
	std::ifstream inFile;
	inFile.open(fileName);
	if (!inFile.is_open()) {
		std::cout << "Failed to open file (setNewInitVals): " << fileName << std::endl;
	}
	else {
		while (!inFile.eof()) {
			int temp;
			inFile >> temp;
			initialVals.push_back(temp);
		}
		inFile.close();
		if (inFile.is_open()) {
			std::cout << "Failed to close file (setNewInitVals): " << fileName << std::endl;
		}
	}
}

void FileManager::createNewFile(std::string fileName) {
	std::ofstream newFile;
	newFile.open(fileName);
	if (!newFile.is_open()) {
		std::cout << "Failed to create new file" << std::endl;
		return;
	}
	fileNames.push_back(fileName);
	newFile.close();
	if (newFile.is_open()) {
		std::cout << "Failed to close new file" << std::endl;
	}
}

int FileManager::removeFile(std::string fileName) {
	const char* removeName = fileName.c_str();
	return remove(removeName);
}

std::vector<std::string> FileManager::readFile(std::string fileName) {
	std::vector<std::string> vec;
	std::ifstream inFile;
	inFile.open(fileName);
	if (!inFile.is_open()) {
		std::cout << "Error opening file (readFile): " << fileName << std::endl;
	}
	else {
		while (!inFile.eof()) {
			std::string val;
			inFile >> val;
			vec.push_back(val);
		}
		inFile.close();
		if (inFile.is_open()) {
			std::cout << "Error closing file (readFile): " << fileName << std::endl;
		}
	}
	return vec;
}

void FileManager::writeFile(std::vector<std::string> fileContent, std::string fileName) {
	std::ofstream oFile;
	oFile.open(fileName, std::ios::app);
	if (!oFile.is_open()) {
		std::cout << "Error opening file (writeFile): " << fileName << std::endl;
	}
	else {
		for (int i = 0; i < fileContent.size(); ++i) {
			oFile << fileContent.at(i) << std::endl;
		}
		oFile.close();
		if (oFile.is_open()) {
			std::cout << "Error closing file (writeFile): " << fileName << std::endl;
		}
	}
}

std::vector<int> FileManager::getInitialVals() {
	return initialVals;
}

FileManager::~FileManager() {
	if (fileNames.size() != initialVals.at(0)) {
		std::cout << "Error removing files: number of files removed does not equal number created" << std::endl;
	}
	for (int i = 0; i < fileNames.size(); ++i) {
		if (removeFile(fileNames.at(i)) != 0) {
			std::cout << "Error removing file: " << fileNames.at(i) << std::endl;
		}
	}
	initialVals.clear();
	fileNames.clear();
}