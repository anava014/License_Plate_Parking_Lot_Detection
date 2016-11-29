#include <iostream>
#include "LicPlateCV.h"

using namespace std;

int main(){
	LicPlateCV cameraOne("live.jpeg", 5, 1); // filename, check_interval, minute time limit

	cameraOne.beginMonitoring();
}
