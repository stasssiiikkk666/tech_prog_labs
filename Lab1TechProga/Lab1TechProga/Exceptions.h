#pragma once
#include <iostream>
#include <string>

class Exceptions {
private:
	std::string message;
public:
	Exceptions(const std::string& message) : message{ message}{}
	std::string GetMessage() const { return message; }
};