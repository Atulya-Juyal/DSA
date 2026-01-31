class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i : nums) mp[i]++;

        int it = 0;
        int n = mp[0];
        for(int i = it; i < n; i++) nums[i] = 0;

        it += mp[0];
        n += mp[1];
        for(int i = it; i < n; i++) nums[i] = 1;

        it += mp[1];
        n += mp[2];
        for(int i = it; i < n; i++) nums[i] = 2;

        return;
    }
};