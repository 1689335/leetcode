/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;

        long long max = 0;
        while (i < j) {
            if (height[i] < height[j]) {
                max = std::max(max, (long long)height[i] * (j - i));
                ++i;
            } else {
                max = std::max(max, (long long)height[j] * (j - i));
                --j;
            }
        }

        return max;
    }
};
// @lc code=end

