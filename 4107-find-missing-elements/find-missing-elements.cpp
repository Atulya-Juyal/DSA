class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i : nums){
            mini = min(mini, i);
            maxi = max(maxi, i);
        }

        for(int i = mini + 1; i < maxi; i++){
            if(!count(nums.begin(), nums.end(), i)){
                res.push_back(i);
            }
        }

        return res;
    }
};