/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        long long ans = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int ret = nums[i] + nums[l] + nums[r];
                if (ret == target) {
                    return target;
                }

                if (abs(ret - target) < abs(ans - target)) {
                    ans = ret;
                }

                if (ret > target) {
                    --r;
                } else {
                    ++l;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

