#include <iostream>
#include "LicPlateCV.h"

using namespace std;

int main(){
	LicPlateCV cameraOne("live.jpeg", 5, 1);
	
	cameraOne.beginMonitoring();
}
