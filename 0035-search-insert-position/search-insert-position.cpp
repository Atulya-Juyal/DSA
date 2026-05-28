class Solution {
public:
    int bs(vector<int> nums, int l, int r, int target){
        if(l > r) return l;
        
        int m = l + (r-l)/2;

        if(nums[m] == target) return m;
        else if(nums[m] > target) return bs(nums, l, m-1, target);
        else return bs(nums, m+1, r, target);
    }

    int searchInsert(vector<int>& nums, int target) {
        return bs(nums, 0, nums.size()-1, target);
    }
};