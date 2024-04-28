#ifndef FINDURL_H
#define FINDURL_H

#include <iostream>
#include <iostream>
#include <functional>
#include <stdexcept>

// Files
#include "ICommand.h"
#include "AddUrl.h"
#include "Data.h"

// Find Url - prints the results of the url search
class FindUrl : public ICommand
{
private:
    Data& data;

public:
    // empty constructor
    //FindUrl();
    // constructor using data
    FindUrl(Data& data);
    // check if the bitArray at the index of the hash is true or false and print it
    void execute(std::string url, std::string& result) override;
};

#endif
