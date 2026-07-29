class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;

        int i = 0;
        int j = 1;

        while(j < nums.size()){
            if((nums[i]-1) * (nums[j]-1) > res){
                res = (nums[i]-1) * (nums[j]-1);
            }
            if(nums[i] < nums[j]){
                i = j;
            }

            j++;
        }

        return res;
    }
};