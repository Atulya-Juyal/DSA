class Solution {
public:
    static bool comparePairs(const pair<char, int>& x, const pair<char, int>& y) {
        if (x.second != y.second) {
            return x.second > y.second;
        }
        return x.first > y.first;
    }

    string frequencySort(string s) {
        int freq[256] = {0};
        for (char c : s) {
            freq[(unsigned char)c]++;
        }

        vector<pair<char, int>> a;
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                a.push_back({(char)i, freq[i]});
            }
        }

        sort(a.begin(), a.end(), comparePairs);

        string res = "";
        for (auto& p : a) {
            res.append(p.second, p.first);
        }

        return res;
    }
};