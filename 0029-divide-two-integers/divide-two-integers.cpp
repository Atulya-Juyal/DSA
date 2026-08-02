class Solution {
public:
    int divide(int dividend, int divisor) {
        long long n = dividend;
        long long d = divisor;

        bool pos = true;
        if(n >= 0 && d < 0) pos = false;
        if(n <= 0 && d > 0) pos = false;

        n = abs(n);
        d = abs(d);

        long long res = 0;

        while(n >= d){
            int cnt = 0;
            while(n >= (d << (cnt+1))) cnt++;
            res += 1LL << cnt;
            n -= (d << cnt);
        }

        if(res == (1LL << 31) && pos) return INT_MAX;
        if(res == (1LL << 31) && !pos) return INT_MIN;

        return pos ? (int)res : (int)-res;
    }
};