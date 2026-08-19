class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        for(int i : nums) mp[i]++;

        int maxi = -1;

        if(k == 1 || k == n){
            for(auto i : mp){
                if(i.second == 1 || k == n){
                    maxi = max(maxi, i.first);
                }
            }
        }

        else{
            if(mp[nums[0]] == 1 && mp[nums[n-1]] == 1){
                maxi = nums[0] > nums[n-1] ? nums[0] : nums[n-1];
            }
            else if(mp[nums[0]] == 1) maxi = nums[0];
            else if(mp[nums[n-1]] == 1) maxi = nums[n-1];
        }

        return maxi;
    }
};