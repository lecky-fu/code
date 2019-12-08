/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

#include <vector>
#include "utils.h"
using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * 动态规划算法实现：
     * 状态转移方程：
     *      dp[m][n]=dp[m-1][n]+dp[m][n-1]  m>0,n>0
     *      dp[m][n]=1                      m=0||n=0
     * 解释：dp[m][n]表示到达坐标(m,n)时，需要的步数，那么其就可以根据坐标(m-1,n)和(m,n-1)的和得出
     * 边界条件m=0和n=0时，路径数均为1
     */
    int uniquePaths(int m, int n) {
        if (m<=0||n<=0)
        {
            return 0;
        }
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        for (size_t i = 0; i < m; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                if (i==0 || j==0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution so;
    CHECK_RESULT("uniquePaths", so.uniquePaths(3,2), 3);
    return 0;
}


