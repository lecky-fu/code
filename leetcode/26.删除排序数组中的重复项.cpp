/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * 
     * 执行过程：找到第一个满足nums[i] != nums[j]的数，然后将其放在i+1的位置
     *      int i = 0, j =1
     *      for j = 1 -->n-1
     *          if target[i] != target[j]
     *              target[++i] = target[j++]
     * 结束条件：j=n-1
     * 边界条件：无
     */
    int removeDuplicates(vector<int>& nums) {
        int lenth = nums.size();
        if (lenth ==0)
        {
            return 0;
        }
        
        int i =0;
        for(int j =1; j< lenth;++j )
        {
            if (nums[i] != nums[j])
            {
                nums[++i] = nums[j];
            }
        }

        return i+1;
    }
};
// @lc code=end

