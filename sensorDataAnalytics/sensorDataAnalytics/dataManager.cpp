#include "dataManager.h"
#include <string>
#include <vector>
#include <iostream>
//adds new measurements
void DataManager::addMeasurement(const Measurement& m) 
{
	measurement.push_back(m);
}

/*************** STATISTICS *******************/
float DataManager::calculateMean() const {
	float sum{};
	for (auto& m : measurement)
	{
		sum += m.value;
	}
	return sum / measurement.size();		//returns the mean value
}
float DataManager::findMin() const {
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
	float var{};
	for (auto& m : measurement)
	{
		var += pow(m.value - calculateMean(), 2);			//Calculates the difference between every element and the mean to the poer of 2 to get a positive number
	}
	float variance = var / measurement.size();				//variance is (value - mean)^2 for all the values and then divide by the numbers of elements
	return sqrt(variance);							//if you take the square root of the variance you get the standard diviation
}

//Printing all the data
void DataManager::printData() const 
{	
	std::cout << "\nTimestamp\t\tTemparture" << std::endl;
	for(auto& m : measurement)
	{
		std::cout << m.timestamp << "\t" << m.value << std::endl;
	}
}
