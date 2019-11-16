//
// Created by lecky-fu on 2019/10/26.
//

#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H
#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include <cstdlib>
#include<set>
#include<string>

using namespace std;

template<class T>
void PRINT_COLL(T& coll)
{
    cout << "[";
    for(const auto &it:coll )
    {
        cout << it << ",";
    }
    cout <<"]"<<endl;
}

template<class T>
void PRINT_NUMS(const T& t)
{
    cout << t << endl;
}

template<typename T>
void CHECK_RESULT(const string funcname,const T result,const T wanted)
{
    if (result != wanted)
    {
        cout<<funcname << " failed,result=" <<result <<",wanted="<<wanted<<endl;
    }
    else
    {
        cout<<funcname <<" ok!"<<endl;
    }
}
#endif //LEETCODE_UTILS_H
