#include "../header/MenuConsole.h"

MenuConsole::MenuConsole(Data& data) : data(data)
{
    addUrl = new AddUrl(data);
    findUrl = new FindUrl(data);

    commands["1"] = addUrl;
    commands["2"] = findUrl;
}

std::string MenuConsole::nextCommand()
{
    std::string line;
    // use get-line to read the entire line, including spaces
    std::getline(std::cin, line);
    // if the line contains valid input - return it
    if (validate(line))
    {
        return line;
    }
    // otherwise - run again
    return nextCommand();
}

bool MenuConsole::validate(std::string input)
{
    // separate the line to first and second words
    std::istringstream iss(input);
    std::string url, task;
    // the first word is a task, the second is an url
    iss >> task >> url;
    try
    {
        // check that task is a number
        int number = std::stoi(task);
        // checking if task appears in the command map, and if the url is not empty
        if (!url.empty() && (commands.count(task) > 0))
        {
            // return true - valid input
            return true;
        }
    // otherwise - return false
    }
    catch (const std::invalid_argument &e)
    {
    }
    catch (const std::out_of_range &e)
    {
    }
    return false;
}

/*
void displayError(String error){
    cout << error;
};
*/

std::unordered_map<std::string, ICommand *> MenuConsole::getCommands()
{
    // Return the set of commands this menu has
    return commands;
}

MenuConsole::~MenuConsole()
{
    // release the memory allocated for addUrl
    delete addUrl;
    // release the memory allocated for findUrl
    delete findUrl;
}
