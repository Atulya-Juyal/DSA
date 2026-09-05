class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suf(n, INT_MAX);
        int mini = INT_MAX;

        for(int i = n-1; i >= 0; i--){
            mini = min(mini, nums[i]);
            suf[i] = mini; 
        }

        int pre = INT_MIN;

        for(int i = 0; i < n; i++){
            pre = max(pre, nums[i]);
            if(pre - suf[i] <= k) return i;
        }

        return -1;
    }
};