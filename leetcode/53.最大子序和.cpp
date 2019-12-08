/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

#include "utils.h"
#include <boost>
// @lc code=start

class Solution {
public:
    /**
     * 第一种方式，遍历已某一个元素作为起始点的所有数组，求最最大和
     */
    int oneWay(vector<int>& nums){
        if (nums.empty())
        {
            return 0;
        }
        
        int result = nums[0];
        for (size_t i = 0; i < nums.size(); i++)
        {
            int plusRes = 0;
            for (size_t j = i; j < nums.size(); j++)
            {
                plusRes += nums[j];
                if (plusRes > result)
                {
                    result = plusRes;
                }
            }
        }
        return result;
    }

    /**
     * 第二种方式，分别遍历长度为1->n的子序列的和，求最大值
     */
    int twoWay(vector<int>& nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        
        int result = nums[0];
        for (size_t i = 1; i <= nums.size(); i++)
        {
            for (size_t j = 0; j < nums.size()-i; ++j)
            {
                //求出[j,i-1]长度的子序列的和
                int temp = 0;
                for (size_t k = j; k <i + j ; ++k)
                {
                    temp += nums[k];
                }
                
                //如果子序列和大于上一个，就赋值
                if (result < temp)
                {
                    result = temp;
                }
            }
        }
        return result;
    }

    /**
     * 第三种遍历方式：以子序列的某一个元素为基准，遍历所有以该节点为结尾的子序列
     * 过程： 
     *      外层：遍历以每一个元素nums[i]作为结束点时，nums[j,i]中最大和的子序列、其中j = [0,i]，然后求所有子序列中的最大值
     *      内层：求子序列nums[j,i]中以i为结尾的最大子序列
     * 结束条件：
     *      外层：i ->[0,n-1]
     *      内层：j = [0,i]
     * 边界条件：nums.size ==0
     **/
    int threeWay(vector<int>& nums) 
    {
        if (nums.empty())
        {
            return 0;
        }
        
        int max_sofar = nums[0];
        for (size_t i = 0; i < nums.size(); i++)
        {
            // int temp = nums[i];
            // if (nums[i] > max_sofar)
            // {
            //     max_sofar = nums[i];
            // }
            int temp = 0;
            for (int j = i; j >= 0; j--)
            {
                temp += nums[j];
                if (temp > max_sofar)
                {
                    max_sofar = temp;
                }
            }
        }
        
        return max_sofar;
    }

    /**
     * 一维数组的动态规划
     * 动态规划：假设nums_end_index[i]和nums_end_sofar[i]已知，那么nums_end_sofar[i+1]即可以依赖于前两个结果算出
     * 初始条件：nums_end_index[i],nums_end_sofar[i]
     * 状态转移方程：
     *      nums_end_index[i+1] = max(nums[i+1], nums_end_index[i]+nums[i+1])
     *      nums_end_sofar[i+1] = max(nums_end_sofar[i],nums_end_index[i+1])
     * 返回结果：return nums_end_sofar[n-1]
     */
    int fourWay(vector<int>& nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        
        int nums_end_index = nums[0];
        int nums_end_sofar = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            nums_end_index = max(nums[i],nums_end_index + nums[i]);
            nums_end_sofar = max(nums_end_sofar, nums_end_index);
        }
        
        return nums_end_sofar;
    }

    /**
     * 动态规划算法解决
     * 1，初始条件
     * 2，状态转移方程
     * 3，结束条件
     */
    int maxSubArray(vector<int>& nums) {
        return threeWay(nums);
    }
};



// @lc code=end
int main(int argc, char const *argv[])
{
    Solution so;
    vector<int> nums{2,1,-3,4,-1,2,1,-5,4};
    PRINT_NUMS(so.maxSubArray(nums));
    return 0;
}

