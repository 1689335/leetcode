/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, 0));
        dp[0][0] = 1;
        for(int i = 2; i <= p.length(); ++i) {
            dp[0][i] = p[i - 1] == '*' && dp[0][i - 2];
        }
        
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 1; j <= p.length(); ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1];
                    if (j >= 2) {
                        dp[i][j] |= dp[i][j - 2];
              
                        if (s[i - 1] == p[j - 2] || (p[j - 2] == '.')) {
                            dp[i][j] |= dp[i - 1][j - 1] | dp[i - 1][j] ;
                        }
                    }
                    
                }
                //cout << "i:" << i << "j:" << j << " " << dp[i][j] << endl;
            }
            
        }
        return dp[s.length()][p.length()];
    }
};
// @lc code=end

