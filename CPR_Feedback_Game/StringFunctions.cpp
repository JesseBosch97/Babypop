#include "StringFunctions.h"

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
