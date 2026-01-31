class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        unordered_map<int, int> mp;

        int sum = 0;
        int res = INT_MIN;

        for(int i : nums){
            sum += i;

            if(sum >= res) res = sum;

            if(sum < 0) sum = 0;
        }

        return res;
    }
};