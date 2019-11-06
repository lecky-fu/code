/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include"utils.h"
// @lc code=start
class Solution {
public:

    /**
     * 直接使用遍历的方式计算：
     * 执行过程：对于每一个元素f(i)，需要找出f(j) - f(i) >0的最大值，其中j>i
     * 结束条件：
     *      外层循环：i=[0,n-1]
     *      内层循环：j=[i+1,n-1]
     * 边界条件：prices.size()=0
     */
    int oneWay(vector<int>& prices)
    {
        if (prices.empty())
        {
            return 0;
        }
        
        int res = 0;
        for (size_t i = 0; i < prices.size(); i++)
        {
            for (size_t j = i+1; j < prices.size(); j++)
            {
                int temp = prices[j] - prices[i];
                if ( temp > res)
                {
                    res = temp;
                }
            }
        }
        
        return res;
    }

    /**
     * 动态规划算法实现：
     * 状态转移方程：
     *      min_sofar[n]：表示prices[0,n]中最小的价格，其中min_sofar为数组，记录到达每一天时，最小的价格数
     *      max_sofar(n)：表示prices[0,n]最大的获利
     *      max_sofar[n+1] 
     *          = max(max_sofar[n],prices[n+1] - min_sofar[n])   prices[n+1] - min_sofar[n] >0  第n天价格如果大于前n-1天的最小价格，才能获利
     *          = 0                                              prices[n+1] - min_sofar[n] <=0 第n天价格如果小于前n-1天的最小价格，那么获利为0
     * 初始条件：
     *      min_sofar[0] = prices[0]
     *      max_sofar(0) = 0
     * 边界条件：股票交易规则 n+1天
     *      prices.size()=1 return 0;
     */
    int twoWay(vector<int>& prices) 
    {   
        vector<int>::value_type size =  prices.size();
        if(size <= 1) return 0;

        vector<int> min_sofar(size);
        min_sofar[0] = prices[0];
        int max_sofar = 0, result = 0;
        for (size_t i = 1; i < size; i++)
        {
            min_sofar[i] = min(min_sofar[i-1], prices[i]);
            int temp = prices[i] - min_sofar[i-1];
            (temp <= 0) ? max_sofar = 0 : (max_sofar = max(max_sofar, temp));

            // if (temp <= 0)
            // {
            //     max_sofar = 0;
            // }
            // else
            // {
            //     max_sofar = max(max_sofar, prices[i] - min_sofar[i-1]);
            // }
            
            //注意此处最终结果是需要额外放置，不能以max_sofar作为最终结果，因为存在不获利的情况
            if (result < max_sofar)
            {
                result = max_sofar;
            }
            
            
        }
        return result;
    }

    int maxProfit(vector<int>& prices) {
        return twoWay(prices);
    }
};
// @lc code=end

