#include "../header/App.h"

App::App() = default;

void App::run()
{
    // create a new first menu
    firstMenu = new FirstMenu();
    // get the data from the first input line via the first menu
    std::vector<int> input = firstMenu->getFirstLine();
    // create a new data with the first input line
    data = Data(input);
    // create a new menu console with the data from the first input line
    menu = new MenuConsole(data);
    // get the menu's commands
    commands = menu->getCommands();

    // run the app forever by getting menu choices and executing them
    while (true)
    {
        // get input from user via the menu
        std::string inputLine = menu->nextCommand();
        // separate the line to url and task
        std::istringstream iss(inputLine);
        std::string url;
        std::string task;
        iss >> task;
        iss >> url;

        // execute the chosen task on the url
        commands[task]->execute(url);
    }
}

App::~App()
{
    // free the memory allocated for the first menu
    delete firstMenu;
    // free the memory allocated for the regular menu
    delete menu;
}