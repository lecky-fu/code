/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include "utils.h"
// @lc code=start
class Solution {
public:

    /**
     * 状态转移方程：f(n) = f(n-1) + f(n-1)
     * 初始条件：f(1) = 1,f(2) =2
     * 边界条件:f(0) = 0
     */
    int oneWay(int n)
    {
        if (n ==0) return 0;
        else if(n ==1) return 1;
        else if(n ==2) return 2;
        else return oneWay(n-1) + oneWay(n-2);
    }

    /**
     * 原问题抽象：再爬到第n级台阶时，必定会从第n-1或者是n-2级台阶经过，那么总数就是f[n-1]+f[n-2]
     * 状态转移方程：f(n) = f(n-1) + f(n-1)
     * 边界条件：f[1] =1，f[0]=1这样做出来更漂亮
     * 使用数组缓存优化上述算法
     */
    int twoWay(int n)
    {
        if (n ==0) return 0;
        else if(n ==1) return 1;
        else if(n ==2) return 2;

        vector<int> f(n+1);
        f[0] = 0,f[1] = 1,f[2] = 2;
        for (size_t i = 3; i <= n; i++)
        {
            f[i] = f[i-1] + f[i-2];
        }
        
        return f[n];
    }

    int climbStairs(int n) {
        return twoWay(n);
    }
};
// @lc code=end

