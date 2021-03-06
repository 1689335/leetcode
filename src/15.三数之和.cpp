/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    void fourSum(vector<vector<int>> &ret, vector<int>& nums, int target, int i, int j) {
        target -= nums[i];
        for (int m = i + 1; m <=j; ++m) {
            int t = target - nums[m];
            int l = m + 1;
            int r = j;

            if (m > i + 1 && nums[m] == nums[m - 1]) {
                continue;
            }
            //cout << i << " " << m << " " << l << " " << r << endl;
            while (l < r) {
                if ((nums[l] + nums[r]) < t) ++l;
                else if ((nums[l] + nums[r]) > t) --r;
                else {
                    ret.push_back(vector<int>{nums[i], nums[m], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l + 1]) ++l;
                    while(l < r && nums[r] == nums[r - 1]) --r;
                    ++l; --r;
                }

            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            fourSum(ret, nums, target, i, nums.size() - 1);
        }
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());

        return ret;
    }
};
// @lc code=end

