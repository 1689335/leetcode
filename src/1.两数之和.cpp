/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            m[target - nums[i]] = i;
        }

        for (int i = 0; i <  nums.size(); ++i) {
            auto it = m.find(nums[i]);
            if (it != m.end()) {
                if (it->second != i) {
                    return {i, it->second};
                }
            }
        }
        return {-1, -1};
    }
};
// @lc code=end

