/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l = 0;
        int r = 0;
        int max = 0;
        
        char c[255] = {0};
        
        for (r = 0; r < s.length(); ++r) {
            if (c[s[r]] == 0) {
                c[s[r]]++;
            } else {
                for (int k = l; k < r; ++k) {
                    if (s[k] == s[r]) {
                        ++l;
                        break;
                    }
                    c[s[l]]--;
                    ++l;   
                }
            }
            
            max = std::max(max, r - l + 1);
            
        }
            
        return max;
    }
};
// @lc code=end

