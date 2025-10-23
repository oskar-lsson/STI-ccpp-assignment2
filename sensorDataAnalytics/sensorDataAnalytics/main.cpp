// sensorDataAnalytics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "dataManager.h"
#include "measurement.h"

int main()
{
	DataManager tempSensor;
	std::string time;
	float val;
	bool testloop = true;
	int userChoice; int iterations{};

	tempSensor.loadFromFile("sensorMeasurements.csv");
	while (testloop)
	{

		int menuChoice;
		std::cout << ""
			"\n_______MENU_______\n"
			"\n[1] Add new values "
			"\n[2] Display statistics "
			"\n[3] Exit" << std::endl;
		std::cout << "Menu choice: "; std::cin >> menuChoice;
		switch (menuChoice)
		{
		case 1: 
			std::cout << "\nHow many measurement do you wish to enter? "; std::cin >> userChoice;
			for (int i = 0; i < userChoice; i++)
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // rensar ev. buffert
				std::cout << "\nTimestamp (YYYY-MM-DD HH:MM): "; std::getline(std::cin, time);
				std::cout << "\nValue: "; std::cin >> val;
				tempSensor.addMeasurement({ time, val });
			}
			break;
		case 2: 
			tempSensor.printData();
			std::cout << "mean: " << tempSensor.calculateMean() << std::endl;
			std::cout << "min: " << tempSensor.findMin() << std::endl;
			std::cout << "max: " << tempSensor.findMax() << std::endl;
			std::cout << "standard diviation: " << tempSensor.calcStandardDeviation() << std::endl;
			break;
		case 3:
			tempSensor.saveToFile("sensorMeasurements.csv");
			exit(0);
		default:
			std::cerr << "\nERROR: Menu not found" << std::endl;
			break;

		}
	}
	return 0;
}
