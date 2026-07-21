class Solution {
public:
    long long helper(string s, long long num, int i, int sign){
        if(i >= s.size() || !isdigit(s[i])) return sign * num;
        num = num*10 + (s[i]-'0');
        if(sign * num >= INT_MAX) return INT_MAX;
        if(sign * num <= INT_MIN) return INT_MIN;

         

        return helper(s, num, i+1, sign);
    }

    int myAtoi(string s) {
        long long num = 0;
        int i = 0;

        while(i < s.size() && s[i] == ' ') i++;

        int sign = 1;
        if(s[i] == '-' || s[i] == '+'){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        } 

        num = helper(s, num, i, sign);
        return (int)num;
    }
};