class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        int res = INT_MAX;

        while(l <= r){
            int m = l + (r-l)/2;

            if(nums[l] <= nums[m]){
                res = min(res, nums[l]);
                l = m + 1;
            }
            else{
                res = min(res, nums[m]);
                r = m - 1;
            }
        }

        return res;
    }
};