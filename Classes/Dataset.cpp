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
	string inputFile;
	string period;
	vector<string> outputFiles;

public:
	Dataset(string inputFile, bool BreakingHigshDatasets = false, bool allHistoricalDataset = false) {
		this->inputFile = inputFile;

		if (BreakingHigshDatasets) {
			string Bullrun2017 = "Daily-2017-Feb-23-to-2017-Dec-17.csv";
			string Bullrun2021 = "Daily-2020-Nov30-to-21-Apr-14.csv";

			dataCreate(Bullrun2017);
			dataCreate(Bullrun2021);

			this->outputFiles.push_back(Bullrun2017);
			this->outputFiles.push_back(Bullrun2021);
		}

		if (allHistoricalDataset) {
			this->outputFiles.push_back("BTC-USD-Daily-Yahoo.csv");
		}
	};

	~Dataset() {
		
	}

	void dataCreate(const string& filename) {
		if(fileExists(filename)) {
			// do nothing
		} else {
			string customPath = "./Clean Data/" + filename; 
			ofstream file(customPath);
			if (file) {
				cout << "File created: " << customPath << endl;
			} else {
				cout << "Failed to create file: " << customPath << endl;
			}
		}
	}
	

	bool fileExists(const string& filename) {
		ifstream file(filename.c_str());
		return file.good();
	}

	string toString() {
		return "Dataset: " + inputFile + " \n" ;
		//still need to return other files
	}


};

#endif 
