/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

#include<vector>
#include"utils.h"
using namespace std;
// @lc code=start
class Solution {
public:
    /**
     * 动态规划算法实现
     * 状态转移方程：
     *      dp[m][n] = min(dp[m-1][n],dp[m][n-1]) + grid[m][n]  m>0,n>0
     *      dp[m][n] = dp[m][n-1] + grid[m][n]                  m=0
     *      dp[m][n] = dp[m-1][n] + grid[m][n]                  n=0
     * 解释：dp[m][n]表示到达坐标(m,n)时的最小值
     */
    int minPathSum(vector<vector<int>>& grid) {
        vector<int>::size_type m = grid.size();
        vector<int>::size_type n = grid.front().size();
        if (m==0 || n ==0)
        {
            return 0;
        }
        
        vector<vector<int>> dp(m, vector<int>(n,0));
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (i==0&&j==0)
                {
                    dp[i][j] = grid[i][j];
                }
                else if (i==0&&j>0)
                {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }
                else if (i>0&&j==0)
                {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
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
    vector<vector<int>> grid={{1,3,1},{1,5,1},{4,2,1}};
    CHECK_RESULT("minPathSum",so.minPathSum(grid),7);
    return 0;
}
