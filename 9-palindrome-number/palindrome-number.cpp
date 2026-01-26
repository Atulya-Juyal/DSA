class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long rev = 0;
        int y = x;
        while(x != 0){
            rev *= 10;
            rev += x%10;
            x = x/10;
        }
        if(rev == y) return true;
        return false;
    }
};