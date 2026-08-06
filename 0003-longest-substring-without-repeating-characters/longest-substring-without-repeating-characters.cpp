class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int i = 0;
        int j = 0;

        int cnt = 0;
        int res = 0;

        while(j < s.size()){
            if(mp.find(s[j]) != mp.end()){
                while(mp[s[j]]){
                    mp[s[i]]--;
                    i++;
                    cnt--;
                }
            }
            mp[s[j]]++;
            cnt++;
            j++;

            res = max(res, cnt);
        }

        return res;
    }
};