#ifndef MenuSocket_h
#define MenuSocket_h

#include <iostream>
#include <sstream>
#include <string>
#include "Data.h"
#include "IMenu.h"
#include "AddUrl.h"
#include "ICommand.h"

// Menu Console - the menu dedicated for reading and validating commands from the user
class MenuSocket : public IMenu
{
private:
    Data& data;
    ICommand *addUrl;
    ICommand *findUrl;
    int sockfd;
    std::unordered_map<std::string, ICommand *> commands;

public:
    // constructor with existing data
    MenuSocket(Data& data, int socketfd);
    // empty constructor
    //MenuConsole();
    // gets the input line and returns it if valid, runs again otherwise
    std::string nextCommand() override;
    // return true if the input is valid, false otherwise
    bool validate(std::string input);
    // returns the menu's set of commands
    std::unordered_map<std::string, ICommand *> getCommands() override;
    // destructor - releases the allocated memory
    ~MenuSocket();
};

#endif /* MenuSocket_h */
