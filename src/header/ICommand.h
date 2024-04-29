#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <map>
#include <string>

// Commands Interface - executes the menu commands
class ICommand
{
public:
    // executes the command using the url
    virtual void execute(std::string url, std::string& result) = 0;
    // releases the allocated memory
    virtual ~ICommand() = default;
};

#endif
