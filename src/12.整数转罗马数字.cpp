/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        string ret;
        
        string s[] = {
            "",
            "M",
            "MM",
            "MMM"
        };
        
        string h[] = {
            "",
            "C",
            "CC",
            "CCC",
            "CD",
            "D",
            "DC",
            "DCC",
            "DCCC",
            "CM"
        };
        
        string t[] = {
            "",
            "X",
            "XX",
            "XXX",
            "XL",
            "L",
            "LX",
            "LXX",
            "LXXX",
            "XC"
        };
        
        string d[] = {
            "",
            "I",
            "II",
            "III",
            "IV",
            "V",
            "VI",
            "VII",
            "VIII",
            "IX"
        };
        
        
        
        int tmp = num / 1000;
        num %= 1000;
        
        ret.append(s[tmp]);
    
        
        tmp = num / 100;
        num %= 100;
        
        ret.append(h[tmp]);
        
        tmp = num / 10;
        num %= 10;
        
        ret.append(t[tmp]);
        
        ret.append(d[num]);
        
        return ret;
        
    }
};
// @lc code=end

