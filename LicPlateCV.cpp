#include "LicPlateCV.h"

LicPlateCV::LicPlateCV(string pathToImage){
	_pathToImage = pathToImage;
}

void LicPlateCV::beginMonitoring(){
	//While loop
	vector<string> currentCars = extractPlateInfo();

	for(unsigned i = 0; i < currentCars.size(); ++i){
		cout << currentCars[i] << endl;
	}
}

string LicPlateCV::runCommand(string command){
	FILE *fp;
	char path[1035];

	/* Open the command for reading. */
	fp = popen(command.c_str(), "r");

	if (fp == NULL) {
		printf("Failed to run command\n" );
		exit(1);
	}

	string output = "";
	while (fgets(path, sizeof(path)-1, fp) != NULL) {
		output += path;
	}

	/* close */
	pclose(fp);

	return output;
}

vector<string> LicPlateCV::extractPlateInfo(){
	stringstream ss;
	//citationsDb.addCitation("9876543", "8:00", "10:00"); //2016-11-11 05:00:00

	string results = runCommand("alpr -n 1 " + _pathToImage);
	ss.str(results);

	string parser;

	vector<string> licPlates;

	while(ss >> parser){
		if(parser == "-"){
			ss >> parser;
			licPlates.push_back(parser);
		}
	}

	return licPlates;
}

void LicPlateCV::printTables(){
	citationsDb.printCitations();
}
