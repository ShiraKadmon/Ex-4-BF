#include "../header/FirstMenu.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

const int DATA_ARRAY_SIZE = 3;

FirstMenu::FirstMenu() = default;


// Function to read one byte at a time from a socket until '\n' is received
std::string readSockLine(int sockfd) {
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

    if (size == -1) {
        // Handle errors appropriately
        perror("recv failed");
    }

    return line;
}

std::vector<int> FirstMenu:: getFirstLine(int sockfd) {
    
    std::string line = readSockLine(sockfd);
    send(sockfd, "1", 1, 0);
    // the array of data to send to the Data constructor
    std::vector<int> dataArr(DATA_ARRAY_SIZE, 0);

    if (!validation(line)) {return std::vector<int>(); }
    
    // separate the line to first and second words
    std::istringstream iss(line);
    std::string arraySize, hash;
    // the first word is the size of the array, the second is the hash
    iss >> arraySize;
    // convert the bit array size to int
    size_t bitArraySize = stoi(arraySize);
    // put the size of the bit array in the first index of the array
    dataArr[0] = bitArraySize;
    // try to convert the hashes input to int
    while (iss >> hash)
    {
        // put the hash number in the first available place in the array
        int hashNumber = stoi(hash);
        // if hash1 appears for the first time
        if ((hashNumber == 1) && (dataArr[1] != 1) && (dataArr[2] != 1))
        {
            // put hash1 in the first available place in the array
            if (dataArr[1] == 0) {
                dataArr[1] = 1;
            }
            else {
                dataArr[2] = 1;
            }
        }
        // if hash1 appears for the first time
        else if ((hashNumber == 2) && (dataArr[1] != 2) && (dataArr[2] != 2))
        {
            // put hash2 in the first available place in the array
            if (dataArr[1] == 0) {
                dataArr[1] = 2;
            }
            else {
                dataArr[2] = 2;
            }
        }
    }
    return dataArr;
}

std::vector<int> FirstMenu::getFirstLine()
{
    // get the input line
    std::string line;
    std::getline(std::cin, line);
    // if the line contains valid input - return it
    if (validation(line))
    {
        // separate the line to first and second words
        std::istringstream iss(line);
        std::string arraySize, hash;
        // the first word is the size of the array, the second is the hash
        iss >> arraySize;
        // the array of data to send to the Data constructor
        std::vector<int> dataArr(DATA_ARRAY_SIZE, 0);

        // convert the bit array size to int
        size_t bitArraySize = stoi(arraySize);
        // put the size of the bit array in the first index of the array
        dataArr[0] = bitArraySize;
        // try to convert the hashes input to int
        while (iss >> hash)
        {
            // put the hash number in the first available place in the array
            int hashNumber = stoi(hash);
            // if hash1 appears for the first time
            if ((hashNumber == 1) && (dataArr[1] != 1) && (dataArr[2] != 1))
            {
                // put hash1 in the first available place in the array
                if (dataArr[1] == 0) {
                    dataArr[1] = 1;
                }
                else {
                    dataArr[2] = 1;
                }
            }
            // if hash1 appears for the first time
            else if ((hashNumber == 2) && (dataArr[1] != 2) && (dataArr[2] != 2))
            {
                // put hash2 in the first available place in the array
                if (dataArr[1] == 0) {
                    dataArr[1] = 2;
                }
                else {
                    dataArr[2] = 2;
                }
            }
        }
        return dataArr;
    }
    // if the input is invalid - run again
    else
    {
        return getFirstLine();
    }
}

bool FirstMenu::validation(std::string line)
{
    // separate the line to different words
    std::istringstream iss(line);
    std::string word;
    // start with the first input word
    bool firstWord = true;
    // try to convert the input words to int
    while (iss >> word)
    {
        try
        {
            int num = stoi(word);
            // if the word is not the first in the line
            if (!firstWord)
            {
                // check for valid input: hash number can only be 1 or 2
                if ((num != 1) && (num != 2))
                {
                    return false;
                }
            }
            // after the first loop iteration we're done with the first word
            firstWord = false;
        }
        // if a word isn't convertable - the input is invalid
        catch (const std::invalid_argument &e)
        {
            return false;
        }
        catch (const std::out_of_range &e)
        {
            return false;
        }
    }
    // the input is valid
    return true;
}
