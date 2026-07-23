class Solution {
public:
    void solve(vector<int>& nums, int i, int s, vector<vector<int>>& res, vector<int>& cur, int k){
        if(s >= k || i == nums.size()){
            if(s == k) res.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        s += nums[i];
        solve(nums, i+1, s, res, cur, k);

        cur.pop_back();
        s -= nums[i];
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        solve(nums, i+1, s, res, cur, k);
    }



    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> cur;

        solve(candidates, 0, 0, res, cur, target);

        return res;
    }
};