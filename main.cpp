#include <iostream>
#include "LicPlateCV.h"

using namespace std;

int main(){
	LicPlateCV cameraOne("test.jpg");
	
	cameraOne.beginMonitoring();

	cameraOne.printTables();
}
