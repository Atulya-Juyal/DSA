class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;

        for(int i = 0; i < num.size(); i++){
            while(!stk.empty() && k > 0 && stk.top() > num[i]){
                stk.pop();
                k--;
            }

            stk.push(num[i]);
        }

        while(k){
            stk.pop();
            k--;
        }

        if(stk.empty()) return "0";

        string res = "";
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }

        while(res.size() != 0 && res.back() == '0') res.pop_back();
        if(res == "") return "0";
        
        reverse(res.begin(), res.end());

        return res;
    }
};