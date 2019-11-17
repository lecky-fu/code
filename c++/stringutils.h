#include <iostream>
#include <cstring>
#include<unordered_set>
#include"../leetcode/utils.h"

namespace utilss
{
    class string
    {
        private:
            char* data;
            int size;
        public:
            string();
            string(const string& str);
            string(const char* c);

            ~string();

            string& operator=(const string &str);
            string& operator=(const char *c);
            int len(){ return size;}
            const char* c_str(){return data;}
            char& operator[](int index)const;
            string& operator+=(const string &str);
            string& operator+=(const char *c);
            //重载<，RB_Tree数据结构排序使用
            bool operator<(const string& str)const;
            
            //友元函数定义，命名空间操作符重载
            friend bool operator==(const string &str1,const string &str2);
            friend std::ostream& operator<<(std::ostream &os,const string &str);
            friend struct stringutilsHash;
            friend struct stringutilsCmp;
    };

    //定义外部仿函数，用于hash数据结构
    struct stringutilsCmp
    {
        bool operator()(const utilss::string &lhs,const string &rhs)const
        {
            if (lhs == rhs)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };
    struct stringutilsHash
    {
        std::size_t operator()(const utilss::string& str)const
        {
            return std::hash<std::string>()(std::string(str.data));
        }
    };

    string::string()
    {
        std::cout << "utils::string default construct;"<<std::endl;
    }

    string::~string(){std::cout << "utils::string ~string construct;"<<std::endl;}

    string::string(const char *c)
    {
        size = strlen(c);
        data = new char[size+1];
        strcpy(data,c);
        std::cout << "utils::string char construct;"<<std::endl;
    }

    string::string(const string& str)
    {
        size = str.size;
        data = new char[size+1];
        strcpy(data,str.data);
        std::cout << "utils::string string construct;"<<std::endl;
    }

    string& string::operator=(const string &str)
    {
        std::cout << "utils::string operator=string construct;"<<std::endl;
        if (this ==&str)
        {
            return *this;
        }

        delete[] data;
        size = str.size;
        data = new char[size+1];
        strcpy(data,str.data);
        return *this;
    }

    string& string::operator=(const char *c)
    {
        std::cout << "utils::string operator=char construct;"<<std::endl;
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

    char& string::operator[](int index) const
    {
        std::cout << "utils::string operator[]char construct;"<<std::endl;
        if (index >0 &&index < size)
        {
            return data[index];
        }
    }

    bool operator==(const string &str1,const string &str2) 
    {
        std::cout << "utils::string operator== construct;"<<std::endl;
        if (&str1 ==&str2)
        {
            return true;
        }
        else if(str1.size != str2.size)
        {
            return false;
        }
        else
        {
            return strcmp(str1.data,str2.data);
        }
    }

    string& string::operator+=(const string &str)
    {
        std::cout << "utils::string operator+=string;"<<std::endl;
        if (str.data)
        {
            string temp(*this);
            size += str.size;
            delete[] data;
            data = new char[size +1];
            strcpy(data,temp.data);
            strcpy(data+temp.size,str.data);
        }
        
        return *this;
    }

    string& string::operator+=(const char * c)
    {
        std::cout << "utils::string operator+=char;"<<std::endl;
        if (c)
        {
            string temp(*this);
            size += strlen(c);
            delete[] data;
            data = new char[size+1];
            strcpy(data,temp.data);
            strcpy(data+temp.size,c);
        }
        
        return *this;
    } 

    std::ostream& operator<<(std::ostream& os, const string & str)
    {
        os << str.data;
        return os;
    }

    void test()
    {
        utilss::string str("sfsdf");
        utilss::string st(str);
        st = str;
        st = "234234";
        st[0];
        std::cout << "st==str : "<<(st==str)<<std::endl;
        std::cout << "st+str : "<<(st+=str)<<std::endl;
        std::cout << "st+str : "<<(st+="99999")<<std::endl;
        std::cout << "st.c_str() : "<<(st.c_str())<<std::endl;

        //hashset
        unordered_set<utilss::string,utilss::stringutilsHash,utilss::stringutilsCmp> myset;
        myset.insert(st);
        myset.insert(str);

        PRINT_COLL("myset",myset);
    }
}

