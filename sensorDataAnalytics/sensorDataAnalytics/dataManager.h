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
	float calcStandardDeviation() const;

	//FILE Manager
	void loadFromFile(const std::string& filename);
	void saveToFile(const std::string& filename);

	//Search for measurments
	void valueSearch() const;
	void timestampSearch() const;

	//sorting
	void sortMeasurements(bool choice);

	//printing data
	void printData() const;

};

