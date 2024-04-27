#include "../header/AddUrl.h"


AddUrl::AddUrl(Data& data) : data(data){}

void AddUrl::execute(std::string url)
{
    // adds the url to the data
    data.addUrl(url);
}
