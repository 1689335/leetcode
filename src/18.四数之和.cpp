/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    set<vector<int>> fourSum(vector<int>& nums, int target, int i, int j) {
        set<vector<int>> ret;
        if (nums[i] > target) {
            return ret;
        }

        target -= nums[i];
        for (int m = i + 1; m <=j; ++m) {
            int t = target - nums[m];
            int l = m + 1;
            int r = j;

            while (l < r) {
                if ((nums[l] + nums[r]) < t) ++l;
                else if ((nums[l] + nums[r]) > t) --r;
                else {
                    ret.insert(vector<int>{nums[i], nums[m], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l + 1]) ++l;
                    while(l < r && nums[r] == nums[r - 1]) --r;
                    ++l;
                    --r;
                }

            }
        }
        return ret;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ret;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            auto t = fourSum(nums, target, i, nums.size() - 1);
        
            copy(t.begin(), t.end(), inserter(ret, ret.begin()));
        }

        return vector<vector<int>>(ret.begin(), ret.end());
    }
};
// @lc code=end

