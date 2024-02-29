#ifndef DATASET_CPP
#define DATASET_CPP

#include <string>
#include <iostream> 
#include <fstream>
#include <filesystem>
#include <vector>

using namespace std;

class Dataset {
private:
	vector<string> outputFiles;

public:
	Dataset(vector<string> rawDataFiles, vector<string> subsectionDataFiles) {

		for(auto file : rawDataFiles) {
			if (filesystem::exists(file)) {
				this->outputFiles.push_back(file);
			} else {
				cerr << "File does not exist: " << file << endl;
			}
		}

		for(auto file : subsectionDataFiles) {
			if (filesystem::exists(file)) {
				this->outputFiles.push_back(file);
			} else {
				cerr << "File does not exist: " << file << endl;
			}
		}
	};

	vector<string> getCleanedFilePaths() {
		return this->outputFiles;
	}
};

#endif 
