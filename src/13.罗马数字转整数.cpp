/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'M') {
                ret += 1000;
            } else if (s[i] == 'D') {
                ret += 500;
            } else if (s[i] == 'L') {
                ret += 50;
            } else if (s[i] == 'V') {
                ret += 5;
            } else if  (s[i] == 'I') {
                if  (i < (s.length() - 1)) {
                    if (s[i + 1] == 'V') {
                        ret += 4;
                        ++i;
                        continue;
                    } else if (s[i + 1] == 'X') {
                        ret += 9;
                        ++i;
                        continue;
                        
                    }
                }
            
                ret += 1;
             } else if  (s[i] == 'X') {
                if  (i < (s.length() - 1)) {
                    if (s[i + 1] == 'L') {
                        ret += 40;
                        ++i;
                        continue;
                    } else if (s[i + 1] == 'C') {
                        ret += 90;
                        ++i;
                        continue;
                        
                    }
                }
            
                ret += 10;
            } else if  (s[i] == 'C') {
                if  (i < (s.length() - 1)) {
                    if (s[i + 1] == 'D') {
                        ret += 400;
                        ++i;
                        continue;
                    } else if (s[i + 1] == 'M') {
                        ret += 900;
                        ++i;
                        continue;
                        
                    }
                }
            
                ret += 100;
            }
        } 
            
        return ret;
        
    }
};
// @lc code=end

