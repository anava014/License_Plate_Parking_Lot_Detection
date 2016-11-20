#include <iostream>
#include "LicPlateCV.h"

using namespace std;

int main(){
	LicPlateCV cameraOne("live.jpeg", 5, 5);
	
	cameraOne.beginMonitoring();

	cameraOne.printTables();
}
