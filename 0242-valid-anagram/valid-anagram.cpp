class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int counts[256] = {0};

        for (int i = 0; i < s.size(); i++) {
            counts[s[i]]++;
            counts[t[i]]--;
        }

        for (int i = 0; i < 256; i++) {
            if (counts[i] != 0) return false;
        }

        return true;
    }
};