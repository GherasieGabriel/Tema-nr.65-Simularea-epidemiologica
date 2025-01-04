#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <iostream>
#include <limits>
#include <string>

bool validateIntInput(int& value, const std::string& prompt);
bool validateFloatInput(float& value, const std::string& prompt, float min = 0.0f, float max = 1.0f);

#endif // INPUTVALIDATOR_H
