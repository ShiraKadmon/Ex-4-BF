#include "../header/MenuSocket.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


// Function to read one byte at a time from a socket until '\n' is received
std::string readLine(int sockfd) {
    std::string line;
    char ch;
    ssize_t size;

    // Continuously read one byte
    while ((size = recv(sockfd, &ch, 1, 0)) > 0) { // Using recv with a size of 1 byte
        if (ch == '\n') {  // Check if the byte is a newline character
            break;  // Exit the loop if newline is found
        }
        line += ch;  // Append the character to the line string
    }

    if(size == 0) {
        return "-1";
    }
    
    if (size == -1) {
        // Handle errors appropriately
        perror("recv failed");
    }

    return line;
}

    
MenuSocket::MenuSocket(Data& data, int sockfd) : data(data), sockfd(sockfd)
{
    addUrl = new AddUrl(data);
    findUrl = new FindUrl(data);

    commands["1"] = addUrl;
    commands["2"] = findUrl;
}

std::string MenuSocket::nextCommand()
{
    std::string line = readLine(sockfd);
    // use get-line to read the entire line, including spaces
    if (validate(line)) {
        return line;
    }
    return "";
}

bool MenuSocket::validate(std::string input)
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

std::unordered_map<std::string, ICommand *> MenuSocket::getCommands()
{
    // Return the set of commands this menu has
    return commands;
}

MenuSocket::~MenuSocket()
{
    // release the memory allocated for addUrl
    delete addUrl;
    // release the memory allocated for findUrl
    delete findUrl;
}
