/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>
#include<memory>
#include<vector>
#include<boost/container/vector.hpp>
#include"utils.h"
using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * 方法一：暴力遍历
     * 过程：
     *      1，给定一个字符串，判断是否为回文
     *      2，遍历字符串s的每一个子字符串，判断其是否是回文字符串
     */
    string oneway(string s){
        for (int i = s.length(); i > 0; --i)
        {
            for (int j = 0; j <= s.length() - i; j++)
            {
                //string.substr return a substring[pos,pos+count);
                string result = s.substr(j,i); 
                if (isPalindrrome(result))
                {
                    return result;
                }
            }
        }
        
        return "";
    }

    bool isPalindrrome(string s){
        int left=0,right=s.length()-1;
        while (left <= right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        
        return true;
    }

    /**
     * 动态规划方法：
     * 状态转移方程：
     *      dp[i][j] = dp[i-2][j+1]&&s[j]==s[i+j-1]     i>2
     *      dp[i][j] = s[j] == s[j+1]                   i=2
     *      dp[i][j] = 1                                i=1
     *      其中dp[i][j]表示长度为i，从第j个开始的子字符串,即s.substr(j,i)
     * 边界条件：s为空
     * 结果：dp[i][j] i从s.length-1开始
     */
    string twoWay(string s){
        string::size_type size = s.size();
        if (0 == size)
        {
            return "";
        }

        vector<vector<int>> dp(size, vector<int>(size,0));
        for (size_t i = 1; i <= size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if (i == 1)
                {
                    dp[i-1][j] = 1;
                }
                else if (i == 2)
                {
                    s[j]==s[j+1]?dp[i-1][j]=1:dp[i-1][j]=0;
                }
                else
                {
                    (dp[i-1-2][j+1]&&s[j]==s[j+i-1])?dp[i-1][j]=1:dp[i-1][j]=0;
                }
            }
        }

        for (size_t i = size-1; i >= 0; --i)
        {
            for (size_t j = 0; j < dp[i].size(); j++)
            {
                if (dp[i][j])
                {
                    return s.substr(j,i+1);
                }
                
            }
        }

        return "";   
    }

    string longestPalindrome(string s) {
        return twoWay(s);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    string s = "kyyrjtdplseovzwjkykrjwhxquwxsfsorjiumvxjhjmgeueafubtonhlerrgsgohfosqssmizcuqryqomsipovhhodpfyudtusjhonlqabhxfahfcjqxyckycstcqwxvicwkjeuboerkmjshfgiglceycmycadpnvoeaurqatesivajoqdilynbcihnidbizwkuaoegmytopzdmvvoewvhebqzskseeubnretjgnmyjwwgcooytfojeuzcuyhsznbcaiqpwcyusyyywqmmvqzvvceylnuwcbxybhqpvjumzomnabrjgcfaabqmiotlfojnyuolostmtacbwmwlqdfkbfikusuqtupdwdrjwqmuudbcvtpieiwteqbeyfyqejglmxofdjksqmzeugwvuniaxdrunyunnqpbnfbgqemvamaxuhjbyzqmhalrprhnindrkbopwbwsjeqrmyqipnqvjqzpjalqyfvaavyhytetllzupxjwozdfpmjhjlrnitnjgapzrakcqahaqetwllaaiadalmxgvpawqpgecojxfvcgxsbrldktufdrogkogbltcezflyctklpqrjymqzyzmtlssnavzcquytcskcnjzzrytsvawkavzboncxlhqfiofuohehaygxidxsofhmhzygklliovnwqbwwiiyarxtoihvjkdrzqsnmhdtdlpckuayhtfyirnhkrhbrwkdymjrjklonyggqnxhfvtkqxoicakzsxmgczpwhpkzcntkcwhkdkxvfnjbvjjoumczjyvdgkfukfuldolqnauvoyhoheoqvpwoisniv";
    Solution so;
    CHECK_RESULT(string("longestPalindrome"),so.longestPalindrome(s),string("qahaq"));
    CHECK_RESULT(string("longestPalindrome"),so.longestPalindrome("babad"),string("bab"));


    //二维vector初始化
    const int SIZE = 100;
    std::vector<std::vector<int>> vecv(SIZE,std::vector<int>(0,SIZE));

    boost::container::vector<int> boostvec;
    boostvec.push_back(100);
    std::cout << "boost"<<boostvec.front();
    return 0;
}
