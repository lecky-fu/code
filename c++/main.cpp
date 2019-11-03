#include <vector>
#include<iostream>
#include"overload.h"
using namespace std;
int main(int argc, char const *argv[])
{
    unordered_set<numPair,numsParisHash,numsPairsCmp> numsSet;
    numsSet.insert(numPair(1,2));
    numsSet.insert(numPair(2,1));
    for(auto const &p:numsSet)
    {
        cout<<p<<","<<endl;
    }
    cout<<"hello,world" <<endl;
    return 0;
}
