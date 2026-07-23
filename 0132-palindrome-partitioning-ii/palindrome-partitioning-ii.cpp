class Solution {
public:
    bool isPalindrome(string& s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }


    int solve(string& s, int i, vector<int>& dp){
        if(i == s.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int minCost = INT_MAX;

        for(int j = i; j < s.size(); j++){
            if(isPalindrome(s, i, j)){
                int cost = 1 + solve(s, j+1, dp);
                minCost = min(minCost, cost);
            }
        }

        return dp[i] = minCost;
    }


    int minCut(string s) {
        vector<int> dp(s.size(), -1);
        int res = solve(s, 0, dp) - 1;
        return res;
    }
};