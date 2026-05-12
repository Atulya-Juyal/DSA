class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int mx = INT_MIN;
        for(int i : nums){
            sum += i;

            if(sum > mx) mx = sum;

            if(sum < 0) sum = 0;
        }
        return mx;
    }
};