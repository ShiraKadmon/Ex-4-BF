#ifndef IMENU_H
#define IMENU_H

#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <string>

// Files
#include "ICommand.h"
#include "AddUrl.h"
#include "FindUrl.h"

class IMenu
{
public:
    // returns the next command from the input
    virtual std::string nextCommand() = 0;
    // returns the menu's set of commands
    virtual std::unordered_map<std::string, ICommand *> getCommands() = 0;
    // a virtual destructor
    virtual ~IMenu() = default;
};

#endif