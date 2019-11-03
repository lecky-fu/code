/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的K-diff数对
 */
#include"utils.h"
// @lc code=start

struct numPair
{
    int i;
    int j;
    numPair(int first,int second)
    {
        i = min(first,second);
        j = max(first,second);
    }

    bool operator< (const numPair&p) const
    {   
        if(i<p.i)
        {
            return true;
        }
        else if(i == p.i && j < p.j)
        {
            return true;
        }

        return false;
    }
    
    friend ostream& operator <<(ostream &out,const numPair&p)
    {
        out <<"("<<p.i<<","<<p.j<<")";
        return out;
    }
};

class Solution {
public:

    /**
     * 暴力遍历法：
     * 执行过程：对于每一个数nums[i]，求nums[i+1,n-1]中，满足|nums[i] - nums[j]| = k的(i,j)对
     * 结束条件：i->[0,n-1]
     * 辅助结构体numPair实现
     * 结果：计数
     */
    int oneWay(vector<int>&nums, int k)
    {
        // int result = 0;
        if(nums.empty())
        {
            return 0;
        }

        set<numPair> resultSet;
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = i+1 ; j < nums.size(); j++)
            {
                if (abs(nums[i] - nums[j]) == k)
                {
                    numPair p(nums[i],nums[j]);
                    resultSet.insert(p);
                }
            }
        }
        return resultSet.size();
    }


    int twoWay(vector<int>&nums,int k)
    {
        sort(nums.begin(), nums.end());
        auto index = unique(nums.begin(),nums.end());
        nums.erase(index,nums.end());
        size_t result =0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = i+1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j] -k)
                {
                    result++;
                    break;
                }
            }
            
        }
        return result;
    }
    /**
     * 过程：
     *      1，排序，去重 
     *      2，遍历数组，找到nums[j] = k-nums[i]的数
     *      3，result++
     * 结束条件：i<size
     */
    int findPairs(vector<int>& nums, int k) {
        return oneWay(nums,k);
    }
};
// @lc code=end


int main(int argc, char const *argv[])
{
    vector<int> nums{3,1,4,1,5};
    Solution so;
    cout << so.findPairs(nums,2);
    PRINT(nums);
    return 0;
}