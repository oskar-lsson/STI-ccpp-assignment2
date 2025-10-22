#pragma once

#include <string>
#include <vector>
#include "measurement.h"

class DataManager
{
private:
	std::vector<Measurement> measurement;
public:
	//adding measurments
	void addMeasurement(const Measurement& m);
	
	//Statistics
	float calculateMean() const;
	float findMin() const;
	float findMax() const;
	float calculateStdDeviation() const;

	//FILE Manager
	void loadFromFile(const std::string& filename);
	void saveToFile(const std::string& filename);

	//printing data
	void printData() const;

};

