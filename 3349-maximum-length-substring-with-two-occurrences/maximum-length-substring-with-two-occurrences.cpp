class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> f(26);

        int i = 0, res = 0;

        for (int j = 0; j < s.size(); j++) {
            f[s[j] - 'a']++;

            while (f[s[j] - 'a'] > 2) {
                f[s[i] - 'a']--;
                i++;
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};