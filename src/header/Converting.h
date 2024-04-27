#ifndef CONVERTING_H
#define CONVERTING_H

#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>
#include <map>
#include <sstream>

// Files
#include "ICommand.h"
#include "AddUrl.h"
#include "FindUrl.h"

class Converting
{
public:
    // Implement the pure virtual function from the interface
    size_t convertStrToSizeT(std::string str);
    int convertStrToInt(std::string str);
};

#endif