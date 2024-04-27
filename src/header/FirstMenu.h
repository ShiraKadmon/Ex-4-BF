#ifndef FIRSTMENU_H
#define FIRSTMENU_H

#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <string>

// Files
#include "ICommand.h"
#include "AddUrl.h"
#include "FindUrl.h"

// First Menu - the menu dedicated for the data in the first input line
class FirstMenu
{
public:
    // constructor
    FirstMenu();
    // get the input line and return the menu data array if valid, run again otherwise
    std::vector<int> getFirstLine();
    // return true if the input is valid, false otherwise
    bool validation(std::string line);
};

#endif