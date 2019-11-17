#include "stringutils.h"
using namespace utilss;
// inline string(const string &str)
// {

// }

// inline bool operator==(const string &str)const
// {
//     return true;
// }

string::string()
{
    std::cout << "utils::string construct;"<<std::endl;
}

string::string(const char *c)
{
    if (!c)
    {
        size = 0;
        delete[] data;
        data = 0;
    }
    else
    {
        size = strlen(c);
        delete[] data;
        data = new char[size+1];
        strcpy(data,c);
    }
    return *this;    
}

string::~string(){}

string& string::operator=(const string &str)
{
    if (this ==&str)
    {
        return *this;
    }

    delete[] data;
    size = strlen(str.data);
    data = new char[size+1];
    strcpy(data,str.data);
    return *this;
}
