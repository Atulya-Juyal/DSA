class Solution {
public:
    void solve(string& digits, int i, vector<string>& res, string& cur, vector<string>& mp){
        if(i == digits.size()){
            res.push_back(cur);
            return;
        }

        for(auto c : mp[digits[i] - '0']){
            cur.push_back(c);
            solve(digits, i+1, res, cur, mp);
            cur.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> res;
        string cur = "";

        solve(digits, 0, res, cur, mp);

        return res;
    }
};