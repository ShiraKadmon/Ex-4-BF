#include "../header/Converting.h"

size_t Converting::convertStrToSizeT(std::string str)
{
    // Convert string to size_t using std::stoul
    try
    {
        size_t num = std::stoul(str);
        return num;
    }
    catch (const std::invalid_argument &e)
    {
        return -1;
    }
    catch (const std::out_of_range &e)
    {
        return -1;
    }
}

int Converting::convertStrToInt(std::string str)
{
    // Convert string to integer
    try
    {
        int num = std::stoi(str);
        return num;
    }
    catch (const std::invalid_argument &e)
    {
        return -1;
    }
    catch (const std::out_of_range &e)
    {
        return -1;
    }
}
