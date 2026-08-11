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

        unordered_set<int> s(nums.begin(), nums.end());

        for(int i = mini + 1; i < maxi; i++){
            if(!s.count(i)){
                res.push_back(i);
            }
        }

        return res;
    }
};