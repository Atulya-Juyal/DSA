class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int k = 0;

        while(i < chars.size()) {
            char c = chars[i];
            int j = i;

            while(j < chars.size() && chars[j] == c) j++;

            chars[k] = c;
            k++;

            int cnt = j - i;

            if(cnt > 1){
                string s = to_string(cnt);
                for(char c : s){
                    chars[k] = c;
                    k++;
                }
            }

            i = j;
        }

        return k;
    }
};