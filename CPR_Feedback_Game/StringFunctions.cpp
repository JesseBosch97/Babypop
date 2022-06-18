#include "StringFunctions.h"
#include <algorithm>


bool detectString(std::string completeString, std::string desiredString)
{
  std::size_t found = completeString.find(desiredString);

  if (found!=std::string::npos)
    {
      return true;
    }
  return false;
}

std::string removeFromString(std::string completeString, std::string unwantedString)
{
  std::string newString = completeString.erase(completeString.find(unwantedString), unwantedString.length());
  return newString;
}

void remove(std::string & completeString, std::string unwantedString)
{
  completeString.erase(completeString.find(unwantedString), unwantedString.length());
}


std::string copyUntil(std::string completeString, char endChar)
{
    std::size_t found = completeString.find_first_of(endChar);
    std::string newString = completeString.substr(0, found);
    return newString;
}

std::string copyAndRemoveNextValue(std::string & data)
{
    std::string string = copyUntil(data, ',');
    std::string unwantedString = ", ";

    remove(data, string);
    remove(data, unwantedString);

    return string;
}

size_t countCharacters(std::string & data, std::string & separationCharacters)
{
    size_t amount = std::count(data.begin(), data.end(), separationCharacters[0]);
    return amount;
}

std::vector<std::size_t> findCharacterLocations(std::string & data, std::string & separationCharacters)
{
    int amountOfChars = countCharacters(data, separationCharacters);
    std::vector<std::size_t> charLocations;
    std::size_t lastCharLocation = 0;

    for (int i = 0; i<amountOfChars; i++)
    {
        lastCharLocation = data.find(separationCharacters, lastCharLocation + 1);
        charLocations.push_back(lastCharLocation);
    }

    return charLocations;
}






