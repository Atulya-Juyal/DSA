class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;

        int res;

        while(l <= r){
            long long m = l + (r-l)/2;

            if(m*m == x) return m;

            else if(m*m < x){
                l = m + 1;
                res = m;
            }
            else r = m - 1; 
        }

        return res;
    }
};