#pragma once
#include <string>
class UserInterface
{
public:
	float getValidInputValue(const std::string& valueMessage);	//checks if userInput is valid
	std::string getValidTimestamp(const std::string& timestampMessage);		//checks if userInput is valid
	void clearWindow(); //Clears the window
};

