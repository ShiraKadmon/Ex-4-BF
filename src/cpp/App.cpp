#include "../header/App.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

App::App(int clientfd):clientfd(clientfd){};

void App::run()
{
    // create a new first menu
    firstMenu = new FirstMenu();
    
    // get the data from the first input line via the first menu
    std::vector<int> input = firstMenu->getFirstLine(clientfd);
    // create a new data with the first input line
    data = Data(input);
    // create a new menu console with the data from the first input line
    menu = new MenuSocket(data, clientfd);
    // get the menu's commands
    commands = menu->getCommands();

    // run the app forever by getting menu choices and executing them
    while (true)
    {
        std::string result;
        // get input from user via the menu
        std::string inputLine = menu->nextCommand();
        if(inputLine.empty()) {continue;}
        if(inputLine == "-1") {break;}
        // separate the line to url and task
        std::istringstream iss(inputLine);
        std::string url;
        std::string task;
        iss >> task;
        iss >> url;
        
        // execute the chosen task on the url
        commands[task]->execute(url, result);
        
        if(result == "false\n" || result == "true false\n" ) {
            send(clientfd, "false\n", 6 , 0);
        }else if(result == "true true\n") {
            send(clientfd, "true\n", 5 , 0);
        }else {
            send(clientfd, result.c_str(), result.size() , 0);
        }
        
    }
}

App::~App()
{
    // free the memory allocated for the first menu
    delete firstMenu;
    // free the memory allocated for the regular menu
    delete menu;
}