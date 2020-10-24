/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        v.insert(v.end(), nums1.begin(), nums1.end());
        v.insert(v.end(), nums2.begin(), nums2.end());
        sort(v.begin(), v.end());
        
        if (v.size() % 2 == 0) {
            return (double)(v[v.size() / 2 - 1] + v[v.size() / 2]) / 2;
        } else {
            return v[v.size() / 2];
        }
        
    }
};
// @lc code=end

