class Solution {
public:
    void solve(vector<int>& nums, int n, int i, vector<vector<int>>& res, vector<int>& cur){
        if(i == n){
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        solve(nums, n, i+1, res, cur);

        cur.pop_back();
        while(i+1 < n && nums[i] == nums[i+1]) i++;
        solve(nums, n, i+1, res, cur);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> res;
        vector<int> cur;

        solve(nums, n, 0, res, cur);

        return res;
    }
};