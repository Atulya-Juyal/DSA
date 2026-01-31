class Solution {
public:
    void sortColors(vector<int>& nums) {
        // unordered_map<int, int> mp;
        // for(int i : nums) mp[i]++;

        // int it = 0;
        // int n = mp[0];
        // for(int i = it; i < n; i++) nums[i] = 0;

        // it += mp[0];
        // n += mp[1];
        // for(int i = it; i < n; i++) nums[i] = 1;

        // it += mp[1];
        // n += mp[2];
        // for(int i = it; i < n; i++) nums[i] = 2;

        // return;

        int l = 0;
        int m = 0;
        int h = nums.size()-1;

        while(m <= h){
            if(nums[m] == 0){
                swap(nums[l], nums[m]);
                l++;
                m++;
            }

            else if(nums[m] == 1) m++;

            else{
                swap(nums[m], nums[h]);
                h--;
            }
        }
    }
};