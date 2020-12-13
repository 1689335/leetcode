#include "gtest/gtest.h"

#include <iostream>
#include <string>
using namespace std;

#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    void proc(set<string> &ret, string &curr, string &digit, int begin, int end)
    {
        if (curr.length() == digit.length()) {
            ret.insert(curr);
            return;
        }

        if (begin >= end) {
            return;
        }

        curr.push_back(digit[0]);
        proc(ret, curr, digit, begin + 1, end);
        curr.pop_back();
    }

    vector<string> letterCombinations(string digits) {
        set<string> ret;
        string curr;
        int num = 0;

        proc(ret, curr, digits, 0, digits.length() - 1);
        
        vector<string> v(ret.begin(), ret.end());

        return v;
    }
};

TEST(TEST, unique)
{
    Solution s;
    auto r = s.letterCombinations("23");
    for (auto i : r) {
        cout << i << endl;
    }
    
}