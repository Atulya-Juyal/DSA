class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i : nums) x = x ^ i;

        unsigned int rightmostSet = (unsigned int)x & (-(unsigned int)x);

        int b0 = 0;
        int b1 = 0;

        for(int i : nums){
            if((unsigned int)i & rightmostSet) b1 = b1 ^ i;
            else b0 = b0 ^ i;
        }

        return {b0, b1};
    }
};