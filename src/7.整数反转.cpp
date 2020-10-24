/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long long y = x;
        int flag = 0;
        if (x < 0) {
            flag = 1;
            y = -y;
        }
        
        long long ret = 0;
        while (y != 0) {
            ret = ret * 10 + y % 10;
            y /= 10;
        }
        
        if (flag) {
            ret = -ret;
        }
        
        if (ret > INT_MAX || ret < INT_MIN) {
            return 0;
        }
        
        return ret;
    }
};
// @lc code=end

