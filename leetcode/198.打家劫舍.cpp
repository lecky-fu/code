/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 *
 * https://leetcode-cn.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (41.98%)
 * Likes:    519
 * Dislikes: 0
 * Total Accepted:    53.5K
 * Total Submissions: 127.5K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 2:
 * 
 * 输入: [2,7,9,3,1]
 * 输出: 12
 * 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
 * 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 * 
 * 
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:

    /**
     * 题解：其实就是要求出给出数组中，不相邻的最大子序列的和
     * 动态规划方法：设f(n)为长度为n的数组的最大值
     * 状态转移方程：f(n) = max(f(n-1),nums[n]+f(n-2))  
     * 解释：假设nums[0,n-1]的最大不相邻子序列为f(n-1)，那么计算f(n)时，
     *      要么不包含nums[n]即最大值为f(n-1)，
     *      要么包含nums[n]即最大值为nums[n] + f(n-2)
     * 初始条件：
     *      f(0) = nums[0]
     *      f(1) = max(f(0),nums[1])
     *      f(2) = max(f(1),nums[2] + f(0))
     * 边界条件：
     *      size ==0 return 0
     *      size ==1 return nums[1]
     * 结果：对于长度为n的数组nums[0,n-1] result = f(n-1)
     */
    int oneWay(vector<int>&nums)
    {
        vector<int>::size_type size = nums.size();
        if(size ==0) return 0;
        if(size ==1) return nums[0];

        vector<int> max_sofar(size);
        max_sofar[0] = nums[0];
        max_sofar[1] = max(max_sofar[0], nums[1]);

        for (size_t i = 2; i < size; i++)
        {
            max_sofar[i] = max(max_sofar[i-1], nums[i] + max_sofar[i-2]); 
        }

        return max_sofar[size-1];
    }


    int rob(vector<int>& nums) {
        return oneWay(nums);
    }
};
// @lc code=end
