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
	int userChoice, menuChoice, searchChoice, sortingChoice;

	tempSensor.loadFromFile("sensorMeasurements.csv");
	while (true)
	{
		ui.clearWindow();
		ui.startMenu();
		menuChoice = ui.getValidInputValue("Enter choice here: ");
		ui.clearWindow();
		switch (menuChoice)
		{
		case 1: 
			userChoice = ui.getValidInputValue("How many measurement do you wish to enter ? ");

			for (int i = 0; i < userChoice; i++)
			{
				std::string time = ui.getValidTimestamp("Timestamp(YYYY - MM - DD HH : MM) : ");
				float val = ui.getValidInputValue("Value: ");
				tempSensor.addMeasurement({ time, val });
			}
			break;
		case 2: 
			tempSensor.printData();
			std::cout << "\nMean: " << tempSensor.calculateMean() << std::endl;
			std::cout << "Min value: " << tempSensor.findMin() << std::endl;
			std::cout << "Max value: " << tempSensor.findMax() << std::endl;
			std::cout << "Standard diviation: " << tempSensor.calcStandardDeviation() << std::endl;
			system("pause");	//waits for the user press any key to continue
			break;
		case 3:
			searchChoice = ui.getValidInputValue("Search by \n[1] Value? \n[2] Timestamp? ");
			switch (searchChoice) {
			case 1:
				tempSensor.valueSearch();
			case 2:
				tempSensor.timestampSearch();
			}
			system("pause");	//waits for the user press any key to continue
			break;
		case 4:
			sortingChoice = ui.getValidInputValue("Sort by \n[1] Value?\n[2] Timestamp? ");
			if (sortingChoice == 1)
			{
				tempSensor.sortMeasurements(true);
			}
			else
			{
				tempSensor.sortMeasurements(false);
			}
			tempSensor.printData();
			system("pause");	//waits for the user press any key to continue
			break;
		case 5:
			tempSensor.saveToFile("sensorMeasurements.csv");
			std::cout << "\n\tA river dirt chee (Arrivederci)\n\n";
			exit(0);

		default:
			std::cerr << "\nERROR: Menu not found" << std::endl;
			break;
		}
	}
	return 0;
}
