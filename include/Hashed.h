#include <iostream>
#include <functional>

#ifndef HASHED_H
#define HASHED_H

class Hashed
{
    public:
        Hashed();
        Hashed(std::string plainStr, std::string salt);
        std::string hash();
        std::string getHashedStr();
        virtual ~Hashed();
    protected:
    private:
        std::string salt;
        std::string plainStr;
        std::string hashedStr;
};

#endif // HASHED_H
