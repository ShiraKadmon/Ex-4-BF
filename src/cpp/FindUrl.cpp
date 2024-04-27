#include "../header/FindUrl.h"
const int BOOL_ARRAY_SIZE = 2;


FindUrl::FindUrl(Data& data) : data(data){}

void FindUrl::execute(std::string url)
{
    // go over the bool array
    std::vector<bool> boolArray = data.findUrl(url);
    for (int i = 0; i < BOOL_ARRAY_SIZE; i++)
    {
        // if it's not the first run - print space
        if(i > 0){
            std::cout << " ";
        }
        // if the boolean value in the array is false - print it
        if (!boolArray[i])
        {
            std::cout << "false";
            break;
        }
        // if the boolean value is true - print it
        else
        {
            std::cout << "true";
        }
    }
    // print a new line
    std::cout << std::endl;
}
