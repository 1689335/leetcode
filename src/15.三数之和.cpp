/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ret;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                return ret;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int m = nums[i] + nums[l] + nums[r];
                if (m > 0) {
                    --r;
                } else if (m < 0) {
                    ++l;
                } else {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) {
                        ++l;
                    }

                    while (l < r && nums[r] == nums[r - 1]) {    
                        --r;
                    }

                    ++l;
                    --r;
                }
            }   
        }
        //sort(ret.begin(), ret.end());
        //ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
};
// @lc code=end

