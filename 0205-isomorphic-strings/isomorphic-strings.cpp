class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> ms(256);
        vector<int> mt(256);

        for(int i = 0; i < s.size(); i++){
            if(ms[s[i]] != mt[t[i]]) return false;

            ms[s[i]] = i + 1;
            mt[t[i]] = i + 1;
        }

        return true;
    }
};