#include "LicPlateCV.h"

LicPlateCV::LicPlateCV(string pathToImage, int checkFrequency, int parkingTimeDuration){
	_pathToImage = pathToImage;
	_checkFrequency = checkFrequency;
	_parkingTimeDuration = parkingTimeDuration;
}

void LicPlateCV::beginMonitoring(){
	//While loop
	

	while(1){
		clearScreen();
		cout << currentTime() << endl;
		// ccDatabase.printCurrentCars();
		scanParkingLot();

		delayProgram(_checkFrequency);
	}
	
}

/*
TO-DO
citations:
check if car has citation already,
else: add citation
*/

void LicPlateCV::scanParkingLot(){
	vector<string> currentCars = extractPlateInfo();

	for(unsigned i = 0; i < currentCars.size(); ++i){
		cout << currentCars[i] << endl;
		if(ccDatabase.isInDatabase(currentCars[i])){
			//cout << "Hes in there - ";
			double minutesParked = ccDatabase.timeInSpot(currentCars[i]);
			cout << "minutesParked: " << minutesParked << endl;
			if(minutesParked > _parkingTimeDuration){
				cout << "Citation will be made" << endl;
			}
		}
		else{
			ccDatabase.addParkedCar(currentCars[i], currentTime());
		}
		//check if car is in database
		//if is, check if it has expired
		//if has, give citation

		//else, add to database
	}
}

void LicPlateCV::delayProgram(double secondsToDelay)
{
	double startTime = double(clock()); //Start timer
	double secondsPassed;
	bool flag = true;
	while(flag)
	{
		secondsPassed = (double(clock() - startTime)) / double(CLOCKS_PER_SEC);;
		if(secondsPassed >= secondsToDelay)
		{
			flag = false;
		}
	}
}

string LicPlateCV::currentTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

    return buf;
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
	ccDatabase.printCurrentCars();
}

void LicPlateCV::clearScreen(){
	cout << "\033c\033[0m";
}






