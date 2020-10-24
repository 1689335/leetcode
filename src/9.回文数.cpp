/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        int data[13];
        int i = 0;
        if (x < 0) {
            return false;
        }
        while (x != 0) {
            data[i++] = x % 10;
            x /= 10;
        }
        
        int m = 0;
        int n = i - 1;
        while (m < n) {
            if (data[m] != data[n]) {
                return false;
            }
            ++m;
            --n;
            
        }
        
        return true;
        
    }
};
// @lc code=end

