#include <iostream>
#include "LicPlateCV.h"

using namespace std;

int main(){
	LicPlateCV cameraOne("test.jpg");

	string result = cameraOne.extractPlateInfo();

	cout << result << endl;

  return 0;
}
