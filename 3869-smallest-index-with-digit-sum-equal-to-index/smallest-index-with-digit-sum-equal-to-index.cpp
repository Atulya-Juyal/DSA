class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int n = 0;

            while(nums[i] && n <= i){
                n += nums[i] % 10;
                nums[i] = nums[i] / 10;
            }

            if(n == i) return i;

        }

        return -1;
    }
};