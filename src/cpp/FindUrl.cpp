#include "../header/FindUrl.h"
const int BOOL_ARRAY_SIZE = 2;


FindUrl::FindUrl(Data& data) : data(data){}

void FindUrl::execute(std::string url, std::string& result)
{
    // go over the bool array
    std::vector<bool> boolArray = data.findUrl(url);
    for (int i = 0; i < BOOL_ARRAY_SIZE; i++)
    {
        // if it's not the first run - print space
        if(i > 0){
            result += " ";
        }
        // if the boolean value in the array is false - print it
        if (!boolArray[i])
        {
            result += "false";
            break;
        }
        // if the boolean value is true - print it
        else
        {
            result += "true";
        }
    }
    
    result += "\n";
}
