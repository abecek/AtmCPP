#include "Hashed.h"

Hashed::Hashed()
{
    //ctor
}

Hashed::Hashed(std::string plainStr, std::string salt):
    plainStr(plainStr),
    salt(salt)
{
    this->hash();
}

std::string Hashed::hash()
{
    if(plainStr != "" && salt != ""){
        std::hash < std::string > hashing;
        hashedStr = hashing(plainStr + salt);
    }
}

std::string Hashed::getHashedStr()
{
    return hashedStr;
}


Hashed::~Hashed()
{
    //dtor
}
