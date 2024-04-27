#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>
#include <map>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <cmath>

class Data
{
private:
    // save the urls
    std::unordered_map<int, std::string> urls = std::unordered_map<int, std::string>();
    // the size of the url
    int urlSize = 0;
    // the bit array
    std::vector<bool> bitArray;
    // the size of the bit array
    size_t bitsSize{};
    // the hash functions
    std::vector<int> hashFunc;
    // the size of the hash functions
    int hashesSize{};

public:
    // empty constructor
    Data();
    // constructor using input vector
    Data(std::vector<int> input);
    // add the input url to the data
    void addUrl(std::string url);
    // searches the input url in the data and returns the results in boolean values
    std::vector<bool> findUrl(std::string url);
    // returns the bit array
    std::vector<bool> getBitArr();
    size_t convertStrToSizeT(std::string str);
    int convertStrToInt(std::string str);
    int getHashSize();
    // returns the saved urls list
    std::unordered_map<int, std::string> getUrls();
};

#endif
