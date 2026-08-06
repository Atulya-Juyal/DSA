class Solution {
public:
    int findProduct(int n){
        int res = 1;

        while(n){
            res *= n % 10;
            n = n / 10;
        }

        return res;
    }
    int smallestNumber(int n, int t) {
        while(findProduct(n) % t != 0) n++;
        return n;
    }
};