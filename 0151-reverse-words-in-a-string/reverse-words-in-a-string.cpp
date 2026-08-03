class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int n = s.size();

        string res = "";
        string word = "";

        while(i < n){
            if(s[i] == ' '){
                if(word != ""){
                    if(res == "") res = word;
                    else res = word + " " + res;
                    word = "";
                }
            }
            else{
                word += s[i];
            }

            i++;
        }

        if(word != ""){
            if(res == "") res = word;
            else res = word + " " + res;
        }

        return res;
    }
};