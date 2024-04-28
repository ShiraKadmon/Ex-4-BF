#include "AddUrl.h"

AddUrl::AddUrl(Data& data) : data(data){}

void AddUrl::execute(std::string url, std::string& result)
{
    // adds the url to the data
    data.addUrl(url);
    result = "1";
}
