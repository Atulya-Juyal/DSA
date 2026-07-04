class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string res = "";

        for(auto i : s){
            if(i == '('){
                if(depth > 0){
                    res += i;
                }
                depth++;
            }
            else{
                depth--;
                if(depth > 0){
                    res += i;
                }
            }
        }

        return res;
    }
};