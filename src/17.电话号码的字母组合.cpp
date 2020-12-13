class Solution {
public:
    vector<string> m = {"", "" ,"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxxyz"};
    void proc(set<string> &ret, string &curr, string &digit, int begin, int end)
    {
        //cout << curr << begin << " " << curr.length() << " " <<  digit.length() << endl;
        if (curr.length() == digit.length()) {
            ret.insert(curr);
            return;
        }

        if (begin > end) {
            return;
        }
        int index = digit[begin] - '0';
        //cout << index << endl;
        for (char j : m[index]) {
            
            curr.push_back(j);
           // cout << j << curr << endl;
            proc(ret, curr, digit, begin + 1, end);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        set<string> ret;
        string curr;
        int num = 0;

        if (digits.length() == 0)
            return vector<string>{};

        proc(ret, curr, digits, 0, digits.length() - 1);
        
        vector<string> v(ret.begin(), ret.end());

        return v;
    }
};