class Solution {
public:
    int distinctSubseqII(string s) {
        int m = 1e9 + 7;
        vector<int> dp(26, 0);

        long long res = 0;

        for(char c : s){
            long long newC = (res + 1) % m;
            res = (res + newC - dp[c - 'a']) % m;

            dp[c - 'a'] = newC;
        }

        if(res < 0) res += m;
        
        return res;
    }
};