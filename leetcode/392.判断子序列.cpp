/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */
#include<string>
#include<iostream>
#include <deque>
using namespace std;
// @lc code=start
/**
 * 算法1,2,3使用一个二维的举证很容易理解
 */
class Solution {
public:

    /**
     * 遍历 o(m*n)
     * 执行过程：
     *      外层循环 i = [0,m)
     *      内层循环 j = [k+1,n)，其中k为字符s[i]再k中第一次出现的位置
     *      判断是否存在s[i] = t[j]
     * 结束条件：
     *      外层循环 i <m
     *      内层循环 j <n  ，对于s[i]，再t中没有找到相等的字符
     * 边界条件：
     *      s.length ==0 true
     *      t.length ==0 false
     */
    bool oneWay(string s, string t)
    {
        if(s.length() ==0) return true;
        if(t.length() ==0) return false;

        size_t k = 0;
        for (size_t i = 0; i < s.length(); ++i)
        {
            size_t j = k;
            for (; j < t.length(); ++j)
            {
                if (s.at(i) == t.at(j))
                {
                    k = j;
                    k++;
                    break;                    
                }
            }

            if(j == t.length()) return false;
        }

        return true;
        
    }

    /**
     * 使用stl算法 o(m*n)
     * 执行过程：
     *      对于s中的每一个字符，再t中查找：
     *      s[i] 再inct中找到的第一个出现的位置为：index = t.find(s[i]);
     *      s[i+1] inct.find(s[i+1], index+1)
     */
    bool twoWay(string s, string t)
    {
        if(s.lengthinc() ==0) return true;
        if(t.lengthinc() ==0) return false;

        string::size_type k = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            string::size_type index = t.find(s[i], k);
            if(index == t.npos) return false;
            k = index;
            k++;
        }
        
        return true;
    }

    /**
     * o(n)
     * 执行过程：
     *      遍历t，查找s中的每一个元素是否出现
     *      如果t[i] != s[j]，i++ 
     *      如果t[i] == s[j]，i++，j++
     * 结束条件：
     *      遍历t结束
     *      j == s.length
     */
    bool threeWay(string s, string t)
    {
        if(s.length() ==0) return true;
        if(t.length() ==0) return false;

        for (size_t i = 0,j = 0; i < t.length(); i++)
        {
            if(t[i] == s[j]) 
                ++j;
            if(j == s.length()) 
                return true;
        }
        
        return false;
    }

    /**
     * 二维数组实现动态规划 o(m*n)
     */
    bool fourthWay(string s, string t)
    {
        bool dp[s.length()+1][t.length()+1];
        for (size_t j = 0; j <= t.length(); j++)
            dp[0][j] = true;
        
        for (size_t i = 1; i <= s.length(); i++)
            dp[i][0] = false;

        for (size_t i = 1; i <= s.length(); i++)
        {
            for (size_t j = 1; j <= t.length(); j++)
            {
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
                if(s[i-1] != t[j-1]) dp[i][j] = dp[i][j-1];
            }
        }
        
        return dp[s.length()][t.length()];
    }

    bool isSubsequence(string s, string t) {
        return fourthWay(s,t);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    /* code */
    Solution so ;
    cout << so.fourthWay("abc","ahbgdc");
    return 0;
}

