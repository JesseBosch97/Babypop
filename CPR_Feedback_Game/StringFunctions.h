#ifndef STRINGFUNCTIONS_H
#define STRINGFUNCTIONS_H

#include <string>
#include <vector>

bool detectString(std::string completeString, std::string desiredString);
std::string removeFromString(std::string completeString, std::string unwantedString);
std::string copyUntil(std::string completeString, char endChar);
void remove(std::string & completeString, std::string unwantedString);
std::string copyAndRemoveNextValue(std::string & data);
size_t countCharacters(std::string & data, std::string & separationCharacters);
std::vector<std::size_t> findCharacterLocations(std::string & data, std::string & separationCharacters);



#endif // STRINGFUNCTIONS_H
