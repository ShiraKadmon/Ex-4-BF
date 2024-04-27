#include "../header/Data.h"

Data::Data() = default;
Data::Data(std::vector<int> input)
{
    // the initial number of hash functions is 0
    int countHashFunc = 0;

    // the initial number of bits is 0
    size_t numBits = input[0];

    // creates a vector of bool (each bool represents a bit)
    bitArray = std::vector<bool>(numBits);

    // accesses and modifies individual bits
    for (size_t i = 0; i < numBits; ++i)
    {
        // initially sets the bit array to false
        bitArray[i] = false;
    }

    // specifies the size of bit array
    bitsSize = numBits;

    // get the length of the input vector
    int len = input.size();
    // gets the number of hash functions
    for (int i = 1; i < len; i++)
    {
        if (input[i] > 0)
        {
            countHashFunc++;
        }
    }
    // sets the number of hash functions
    hashesSize = countHashFunc;

    // set the hash functions vector
    hashFunc = std::vector<int>(countHashFunc);
    countHashFunc = 0;
    for (int i = 1; i < len; i++)
    {
        if (input[i] > 0)
        {
            // set the hash functions
            hashFunc[countHashFunc] = input[i];
            countHashFunc++;
        }
    }
}

void Data::addUrl(std::string url)
{
    // the hash function
    std::hash<std::string> hash_fn;
    long hash;
    // if the user wants to, then we hash it again
    std::string hashAgain;

    // add the url to the map
    urls[urlSize] = url;
    urlSize++;

    // for each hash function, we hash the url and set the bitArray at the index of the hash to true
    for (int i = 0; i < Data::hashesSize; i++)
    {
        // if the user wants to use several times the hash function
        if (hashFunc[i] > 0)
        {
            // hash the url
            hash = hash_fn(url);
            // hash it again if the user wants to
            for (int j = 1; j < hashFunc[i]; j++)
            {
                hashAgain = std::to_string(hash);
                hash = hash_fn(hashAgain);
            }
            // set the hash to absolute value
            if (hash < 0) {
                hash = hash * (-1);
            }
            // set the bitArray at the index of the hash to true
            bitArray[hash % bitsSize] = true;
        }
    }
}

std::vector<bool> Data::findUrl(std::string url)
{
    // the hash function
    std::hash<std::string> hash_fn;
    long hash;
    // if the user wants to, then we hash it again
    std::string hashAgain;
    // the bool array
    std::vector<bool> boolArray(2);
    // for each hash function, we hash the url and set the bitArray at the index of the hash to true
    for (int i = 0; i < hashesSize; i++)
    {
        // if the user wants to use several times the hash function
        if (hashFunc[i] > 0)
        {
            // hash the url
            hash = hash_fn(url);
            // hash it again if the user wants to
            for (int j = 1; j < hashFunc[i]; j++)
            {
                hashAgain = std::to_string(hash);
                hash = hash_fn(hashAgain);
            }
        }
        if (hash < 0) {
            hash = hash * (-1);
        }
        // check if the bitArray at the index of the hash is true or false
        if (getBitArr()[hash % bitsSize]) {
            boolArray[0] = true;
        }
        else
        {
            boolArray[0] = false;
            break;
        }
    }

    bool findUrl = false;
    // check if the url is in the map
    if (boolArray[0]) {
        for (int i = 0; i < urlSize; i++) {
            // if the url is located in the list
            if (url.compare(getUrls()[i]) == 0) {
                // save it anf break
                findUrl = true;
                break;
            }
        }
    }
    // if it's found - set the value to true
    if (findUrl){
        boolArray[1] = true;
    }
    // if not found - set to false
    else
    {
        boolArray[1] = false;

    }
    return boolArray;
}

size_t Data::convertStrToSizeT(std::string str)
{
    // Convert string to size_t
    size_t num = std::stoul(str);
    return num;
}

int Data::convertStrToInt(std::string str)
{
    // Convert string to integer
    int num = std::stoi(str);
    return num;
}
std::vector<bool> Data::getBitArr()
{
    return bitArray;
}
int Data::getHashSize()
{
    return hashesSize;
}

std::unordered_map<int, std::string> Data::getUrls() {
    return urls;
}
