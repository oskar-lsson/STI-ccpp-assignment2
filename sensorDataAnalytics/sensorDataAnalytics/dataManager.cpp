#include "dataManager.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
//adds new measurements
void DataManager::addMeasurement(const Measurement& m) 
{
	measurement.push_back(m);
}

/*************** STATISTICS *******************/
float DataManager::calculateMean() const {
	if (measurement.empty())
	{
		std::cerr << "ERROR: No measurements were found " << std::endl;
		return 1;
	}
	float sum{};
	for (auto& m : measurement)
	{
		sum += m.value;
	}
	return sum / measurement.size();		//returns the mean value
}
float DataManager::findMin() const {
	if (measurement.empty())
	{
		std::cerr << "ERROR: No measurements were found " << std::endl;
		return 1;
	}
	float minValue = measurement[0].value;
	for ( auto& m : measurement)
	{
		if (m.value < minValue)
		{
			minValue = m.value;
		}
	}
	return minValue;		//returns the smallest value
}
float DataManager::findMax() const {
	if (measurement.empty())
	{
		std::cerr << "ERROR: No measurements were found " << std::endl;
		return 1;
	}
	float maxValue = measurement[0].value;
	for (auto& m : measurement)
	{
		if (m.value > maxValue)
		{
			maxValue = m.value;
		}
	}
	return maxValue;			//returns the biggest number
}
float DataManager::calcStandardDeviation() const {
	if (measurement.empty())
	{
		std::cerr << "ERROR: No measurements were found " << std::endl;
		return 1;
	}
	float var{};
	for (auto& m : measurement)
	{
		var += pow(m.value - calculateMean(), 2);			//Calculates the difference between every element and the mean to the poer of 2 to get a positive number
	}
	float variance = var / measurement.size();				//variance is (value - mean)^2 for all the values and then divide by the numbers of elements
	return sqrt(variance);							//if you take the square root of the variance you get the standard diviation
}

//Printing all the data
void DataManager::printData() const {
	if (measurement.empty())
	{
		std::cerr << "PRINT FAILED: No values" << std::endl;
	}
	else
	{
		std::cout << "\nTimestamp\t\tTemparture" << std::endl;
		for(auto& m : measurement)
		{
		std::cout << m.timestamp << "\t" << m.value << std::endl;
		}
	}
}
/********* FILE Manager **********/
//Load measurements from file
void DataManager::loadFromFile(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "ERROR: Failed to open " << filename << std::endl;
	}

	std::string line;
	while (getline(file, line)) {
		std::stringstream ss(line);
		Measurement m;
		getline(ss, m.timestamp, ',');
		ss >> m.value;
		measurement.push_back(m);
	}
}
//saves new values to a file
void DataManager::saveToFile(const std::string& filename) {
	std::ofstream file(filename);
	for (auto& m : measurement) 
	{
		file << m.timestamp << ", " << m.value << "\n";
	}
	file.close();
}

//Value search
void DataManager::valueSearch() const {
	float searchVal;
	bool valueWasFound = false;			//Used to determine if a value was found
	std::cout << "Which value are you looking for? "; std::cin >> searchVal; std::cout << std::endl;
	for (auto& m : measurement)
	{
		if (m.value == searchVal)
		{
			std::cout << "It was " << m.value << " degrees on " << m.timestamp << std::endl;
			valueWasFound = true;
		}
	}
	if (valueWasFound == false)
	{
		std::cout << "\n***Value not found***\n" << std::endl;
	}
}
void DataManager::timestampSearch() const {
	std::string searchTime;
	bool valueWasFound = false;			//Used to determine if a value was found
	std::cout << "Which time are you looking for? "; std::getline(std::cin, searchTime); std::cout << std::endl;
	for (auto& m : measurement)
	{
		if (m.timestamp == searchTime)
		{
			std::cout << "On " << m.timestamp << " it was " << m.value <<" degrees!" << std::endl;
			valueWasFound = true;
		}
	}
	if (valueWasFound == false)
	{
		std::cout << "\n***Timestamp not found***\n" << std::endl;
	}
}
void DataManager::sortMeasurements(bool choice) {
	std::sort(measurement.begin(), measurement.end(),
		[choice](const Measurement& value1, const Measurement& value2) {
			if (choice)
				return value1.value < value2.value;         //ascending order by value
			else
				return value1.timestamp < value2.timestamp;     //ascending order by timestamp
		});
}