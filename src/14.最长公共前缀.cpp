/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        sort(strs.begin(), strs.end());

        for (int i = 0; i < strs[0].length(); ++i) {
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[0][i] != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};
// @lc code=end

