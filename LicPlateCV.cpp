#include "LicPlateCV.h"

LicPlateCV::LicPlateCV(string pathToImage, int checkFrequency, int parkingTimeDuration){
	_pathToImage = pathToImage;
	_checkFrequency = checkFrequency;
	_parkingTimeDuration = parkingTimeDuration;
}

void LicPlateCV::beginMonitoring(){
	while(1){
		clearScreen();
		cout << "Current Time: " << currentTime() << endl;
		scanParkingLot();
		delayProgram(_checkFrequency);
	}
	
}

void LicPlateCV::scanParkingLot(){
	vector<string> currentCars = extractPlateInfo();

	for(unsigned i = 0; i < currentCars.size(); ++i){
		cout << "Car[" << i << "]: " <<  currentCars[i] << endl;
		if(ccDatabase.isInDatabase(currentCars[i])){ // Car is in database
			//cout << "Hes in there - ";
			double minutesParked = ccDatabase.timeInSpot(currentCars[i]);
			cout << "MinutesParked: " << minutesParked << endl;
			if(minutesParked > _parkingTimeDuration){ // Has been there > time allowed
				
				if(citationsDb.isInDatabase(currentCars[i])){
					cout << "Already has citation" << endl;
				}
				else{ //give citation
					cout << "No citation yet: Citation will be made" << endl;
					string timeIn = ccDatabase.returnTimeIn(currentCars[i]);
					citationsDb.addCitation(currentCars[i], timeIn, currentTime());
				}
			}
		}
		else{ // Add car to database
			ccDatabase.addParkedCar(currentCars[i], currentTime());
		}
	}

	ccDatabase.validateDatabase(currentCars, _parkingTimeDuration);
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






