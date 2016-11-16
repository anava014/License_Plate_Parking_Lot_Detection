#include "LicPlateCV.h"

LicPlateCV::LicPlateCV(string pathToImage){
	_pathToImage = pathToImage;
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
	/* Read the output a line at a time - output it. */
	while (fgets(path, sizeof(path)-1, fp) != NULL) {
		output += path;
	}

	/* close */
	pclose(fp);

	return output;
}

string LicPlateCV::extractPlateInfo(){
	return runCommand("alpr " + _pathToImage);
}
