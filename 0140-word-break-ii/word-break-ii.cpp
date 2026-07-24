class Solution {
public:
    void solve(string& s, int i, unordered_set<string>& st, vector<string>& res, vector<string>& cur){
        if(i == s.size()){
            string sen = "";

            for(int w = 0; w < cur.size(); w++){
                sen += cur[w];
                if(w != cur.size()-1) sen += ' ';
            }

            res.push_back(sen);

            return;
        }

        for(int j = i; j < s.size(); j++){
            if(st.count(s.substr(i, j-i+1))){
                cur.push_back(s.substr(i, j-i+1));
                solve(s, j+1, st, res, cur);
                cur.pop_back();
            }
        }
    }


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<string> res;
        vector<string> cur;

        solve(s, 0, st, res, cur);

        return res;
    }
};