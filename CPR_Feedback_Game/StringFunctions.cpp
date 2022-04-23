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

void removeFrom(std::string * completeString, std::string unwantedString)
{
  completeString->erase(completeString->find(unwantedString), unwantedString.length());
}


std::string copyUntil(std::string completeString, char endChar)
{
    std::size_t found = completeString.find_first_of(endChar);
    char buffer[found];

    completeString.copy(buffer, found, 0);
    std::string newString(buffer);

    return newString;
}
