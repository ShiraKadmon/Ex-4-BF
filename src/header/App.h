#ifndef APP_H
#define APP_H

#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>
#include <map>
#include <sstream>
#include <bitset>

// Files
#include "IMenu.h"
#include "ICommand.h"
#include "AddUrl.h"
#include "FindUrl.h"
#include "Converting.h"
#include "Data.h"
#include "MenuSocket.h"

#include "FirstMenu.h"

// App - creates an app and runs it using menu, first menu, commands and data
class App
{
private:
    IMenu *menu{};
    std::unordered_map<std::string, ICommand *> commands;
    Data data;
    FirstMenu *firstMenu{};
    int clientfd;

public:
    // constructor
    App(int clientfd);
    // run the app
    void run();
    // destructor - frees the allocated memory for app
    ~App();
};

#endif
