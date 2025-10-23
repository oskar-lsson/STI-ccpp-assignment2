// sensorDataAnalytics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "dataManager.h"
#include "measurement.h"
#include "userInterface.h"

int main()
{
	DataManager tempSensor;
	UserInterface ui;
	std::string time;
	int userChoice; int menuChoice;

	tempSensor.loadFromFile("sensorMeasurements.csv");
	while (true)
	{
		ui.clearWindow();
		std::cout << ""
			"\n_______MENU_______\n"
			"\n[1] Add new values "
			"\n[2] Display statistics "
			"\n[3] Exit" << std::endl;
		menuChoice = ui.getValidInputValue("Enter choice here: ");
		ui.clearWindow();
		switch (menuChoice)
		{
		case 1: 
			std::cout << "\nHow many measurement do you wish to enter? "; std::cin >> userChoice;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');     //clears the buffert

			for (int i = 0; i < userChoice; i++)
			{
				std::string time = ui.getValidTimestamp("Timestamp(YYYY - MM - DD HH : MM) : ");
				float val = ui.getValidInputValue("Value: ");
				tempSensor.addMeasurement({ time, val });
			}
			break;
		case 2: 
			tempSensor.printData();
			std::cout << "mean: " << tempSensor.calculateMean() << std::endl;
			std::cout << "min: " << tempSensor.findMin() << std::endl;
			std::cout << "max: " << tempSensor.findMax() << std::endl;
			std::cout << "standard diviation: " << tempSensor.calcStandardDeviation() << std::endl;
			system("pause");	//waits for the user press any key to continue
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
