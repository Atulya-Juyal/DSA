class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        vector<string> res(numRows, "");

        int j = 0;
        int d = -1;

        for(int i = 0; i < s.size(); i++){
            if(j == numRows-1 || j == 0) d *= -1;

            res[j].push_back(s[i]);

            if(d == 1) j++;
            else j--;
        }

        string ans = "";
        for(string i : res) ans += i;

        return ans;
    }
};