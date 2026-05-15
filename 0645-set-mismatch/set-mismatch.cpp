class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        long long s = 0;
        long long sn = 0;
        long long v1 = 0;
        long long v2 = 0;

        for(int i : nums) s += i;
        sn = (n*(n+1))/2;
        v1 = s - sn;

        s = 0;
        sn = 0;
        for(int i : nums) s += i*i;
        sn = (n*(n+1)*(2*n+1))/6;
        v2 = s - sn;
        v2 = v2 / v1;

        int x = (v1+v2)/2;
        int y = v2 - x;

        return {x, y};
    }
};