/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start
#include<vector>

using namespace std;
class Solution {
public:

    /**
     * 题解：两个数组合按照顺序合并之后，奇数个第：(m+n)>>1或者是偶数个第：(m+n)>>1和(m+n)>>1 -1
     * 过程：使用额外的数组空间，将两个数组合并，合并之后取目标数，然后求出中位数
     * 结束条件：数组1或者数组2便利结束，然后copy另一个数组的剩余数据到额外数组空间
     * 空间复杂度：O(M+N)
     * 时间复杂度：O(M+N)
     **/
    double wayOne(vector<int>& nums1, vector<int>& nums2){
        vector<int>::size_type m = nums1.size();
        vector<int>::size_type n = nums2.size();
        vector<int> temp(m+n);

        vector<int>::size_type i,j,k=0;
        for ( i = 0,j=0; i < m && j<n; )
        {
            if (nums1[i] < nums2[j])
            {
                temp[k++] = nums1[i++];
            }
            else
            {
                temp[k++] = nums2[j++];
            } 
        }

        if (i == m)
        {
            copy(nums2.begin()+j, nums2.end(), temp.begin()+k);
        }
        else if(j == n)
        {
            copy(nums1.begin()+i,nums1.end(),temp.begin()+k);
        }


        int index = (m+n)>>1;
        if ( (m+n)%2 != 0)
        {
            return temp[index];
        }
        else
        {
            double tem = (double)(temp[index-1] + temp[index]);
            return tem/2;
        }     
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}

// @lc code=end

