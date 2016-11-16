#include <iostream>
#include <stdio.h>      /* printf */
#include <stdlib.h> 
using namespace std;

class LicPlateCV{
private:
	string _pathToImage;
	string runCommand(string command);

public:
	LicPlateCV(string pathToImage);
	string extractPlateInfo();
};
