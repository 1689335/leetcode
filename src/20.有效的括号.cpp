/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        if (s.empty()) {
            return true;
        }

        for (auto ch : s) {
            if (st.empty() || ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
                continue;
            }

            if (ch == ')') {
                char top = st.top();
                st.pop();
                if (top != '(') {
                    return false;
                }
            }

            if (ch == ']') {
                char top = st.top();
                st.pop();
                if (top != '[') {
                    return false;
                }
            }

            if (ch == '}') {
                char top = st.top();
                st.pop();
                if (top != '{') {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
// @lc code=end

