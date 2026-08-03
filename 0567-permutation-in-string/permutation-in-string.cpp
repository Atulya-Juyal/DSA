class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        unordered_map<int, int> s1c;
        unordered_map<int, int> s2c;

        for(int i = 0; i < s1.size(); i++){
            s1c[s1[i]]++;
            s2c[s2[i]]++;
        }

        if(s1c == s2c) return true;

        int l = 0;
        for(int r = s1.size(); r < s2.size(); r++){
            s2c[s2[r]]++;
            s2c[s2[l]]--;

            if(s2c[s2[l]] == 0) s2c.erase(s2[l]);

            l++;

            if(s1c == s2c) return true;
        }

        return false;

    }
};