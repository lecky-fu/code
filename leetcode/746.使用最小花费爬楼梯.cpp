/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include<vector>
#include"utils.h"
using namespace std;
// @lc code=start
class Solution {
public:
    /**
     * 状态转移方程：f(n)表示当前第n级阶梯时，最小的花费值
     *      f(n) = min(f(n-1),f(n-2)) + cost[n]
     * 初始条件：
     *      f(0) = cost[0]
     *      f(1) = cost[1]
     * 结束条件：最终到达终点的方式有两种，倒数第二阶或者时最后一阶
     *      result = min(f(n),f(n-1))
     *      
     */
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());

        for (size_t i = 0; i < cost.size(); i++)
        {
            if(i < 2) 
            {
                dp[i] = cost[i];
            }
            else
            {
                dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
            }
        }
        
        return min(dp[cost.size()-1],dp[cost.size()-2]);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> cost = {0,0,0,0};
    Solution so;
    CHECK_RESULT("minCostClimbingStairs",so.minCostClimbingStairs(cost),0);
    return 0;
}

