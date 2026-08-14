class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0;

        unordered_map<char, int> mp;

        int i = 0;
        int j = 0;

        while(j < s.size()){
            if(mp[s[j]] == 2){
                while(mp[s[j]] == 2){
                    mp[s[i]]--;
                    i++;
                }
            }
            
            mp[s[j]]++;
            j++;

            res = max(res, j-i);
        }

        return res;
    }
};