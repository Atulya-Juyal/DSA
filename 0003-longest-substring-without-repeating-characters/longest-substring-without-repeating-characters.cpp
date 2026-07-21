class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int res = 0;
        int cnt = 0;

        int j = 0;

        for(int i = 0; i < s.size(); i++){
            if(mp[s[i]] == 0){
                mp[s[i]]++;
                cnt++;
            }
            else{
                mp[s[j]]--;
                j++;
                i--;
                cnt--;
            }

            res = max(res, cnt);
        }

        return res;
    }
};