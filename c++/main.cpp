#include <vector>
#include<iostream>
// #include"overload.h"
#include "stringutils.h"
using namespace std;

int main(int argc, char const *argv[])
{
    // unordered_set<numPair,numsParisHash,numsPairsCmp> numsSet;
    // numsSet.insert(numPair(1,2));
    // numsSet.insert(numPair(2,1));
    // for(auto const &p:numsSet)
    // {
    //     cout<<p<<","<<endl;
    // }
    cout<<"hello,world" << endl;
    string s = "sff";
    string t = "fsfsf";
    bool dp[s.length()+1][t.length()+1];

    utilss::string str("sfsdf");
    utilss::string st(str);
    st = str;
    st = "234234";
    st[0];
    std::cout << "st==str : "<<(st==str)<<std::endl;
    std::cout << "st+str : "<<(st+=str)<<std::endl;
    std::cout << "st+str : "<<(st+="99999")<<std::endl;
    return 0;
}
