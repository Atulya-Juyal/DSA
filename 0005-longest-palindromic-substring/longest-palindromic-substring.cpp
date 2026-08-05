class Solution {
public:
    int expand(string& s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }

        return r-l-1;
    }

    string longestPalindrome(string s) {
        string res = "";

        int start = 0;
        int end = 0;

        for(int i = 0; i < s.size(); i++){

            int lenOdd = expand(s, i, i);
            int lenEven = expand(s, i, i+1);

            int len = max(lenOdd, lenEven);

            if(len > end-start+1){
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }

        return s.substr(start, end-start+1);
    }
};