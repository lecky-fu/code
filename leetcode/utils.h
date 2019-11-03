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
void PRINT(const T& coll){
    std::cout <<"[";
    for(const auto &elem:coll){
        std::cout <<elem << ",";
    }
    std::cout <<"]"<<std::endl;
}

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
#endif //LEETCODE_UTILS_H
