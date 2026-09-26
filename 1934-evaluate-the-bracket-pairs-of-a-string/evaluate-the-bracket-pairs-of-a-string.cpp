class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(auto i : knowledge){
            mp[i[0]] = i[1];
        }

        string res = "";
        string key = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] != '(') res += s[i];

            else{
                i++;

                while(s[i] != ')'){
                    key += s[i];
                    i++;
                }
                
                res += mp.contains(key) ? mp[key] : "?";
                key = "";
            }
        }

        return res;
    }
};