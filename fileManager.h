#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
#include <vector>

class FileManager {
private:
	std::vector<int> initialVals; // Initial premade values
	std::vector<std::string> fileNames; // Names of files created
public:
	FileManager();
	FileManager(std::string fileName); // Initializes values from t1.txt ... t4.txt (checked)
	void initialize(std::string fileName);
	void createNewFile(std::string fileName); // Creates new file param name (checked)
	int removeFile(std::string fileName);  // Deletes file of param name (checked)
	std::vector<std::string> readFile(std::string fileName); // reads content in file of param name (checked)
	void writeFile(std::vector<std::string> fileContent, std::string fileName); // writes content to file of param name (checked)
	std::vector<int> getInitialVals(); // returns initial premade values (checked)
	~FileManager(); // destructor deletes all created files and clears initialValues and fileNames (checked)
	
};

#endif