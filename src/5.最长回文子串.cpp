/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        
        int length = 1;
        int begin = 0;
        for (int j = 0; j < s.length(); ++j) {
            dp[j][j] = 1;
        }
        
        for (int j = 1; j < s.length(); ++j) {
            if (s[j] == s[j - 1]) {
                dp[j - 1][j] = 1;
                begin = j - 1;
                length = 2;
            }
        }
        
  
        for (int i = 3; i <= s.length(); ++i) {
            for (int j = 0; j + i <= s.length(); ++j) {
                int end = j + i - 1;
                if (dp[j + 1][end - 1] && s[j] == s[end]) {
                    dp[j][end] = 1;
                    length = i;
                    begin = j;
                }
            }
        }
        
        return s.substr(begin, length);
        
    }
};
// @lc code=end

