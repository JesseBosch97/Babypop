#ifndef STRINGFUNCTIONS_H
#define STRINGFUNCTIONS_H

#include <string>

bool detectString(std::string completeString, std::string desiredString);
std::string removeFromString(std::string completeString, std::string unwantedString);
std::string copyUntil(std::string completeString, char endChar);
void removeFrom(std::string & completeString, std::string unwantedString);
std::string copyAndRemoveNextValue(std::string & data);



#endif // STRINGFUNCTIONS_H
