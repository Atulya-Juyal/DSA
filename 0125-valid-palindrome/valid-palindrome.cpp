class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";

        for(char i : s){
            i = tolower(i);
            if(isalnum(i)) res += i;
        }

        for(int i = 0; i < res.size()/2; i++){
            if(res[i] != res[res.size()-1-i]) return false;
        }

        return true;
    }
};