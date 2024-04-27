#ifndef ADDURL_H
#define ADDURL_H

#include <iostream>
#include <hash_fun.h>
#include <functional>
#include <stdexcept>

// Files
#include "Data.h"
#include "ICommand.h"


// Add Url - adds the url to the saved blacklist
class AddUrl : public ICommand
{
private:
    Data& data;

public:
    // constructor using data
    AddUrl(Data& data);
    // executes the menu choice to add the url to the blacklist
    void execute(std::string url) override;
};

#endif