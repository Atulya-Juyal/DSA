class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int e1 = INT_MIN;
        int e2 = INT_MIN;
        int cnt1 = 0;
        int cnt2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(cnt1 == 0 && nums[i] != e2){
                e1 = nums[i];
                cnt1++;
            }

            else if(cnt2 == 0 && nums[i] != e1){
                e2 = nums[i];
                cnt2++;
            }

            else if(e1 == nums[i]) cnt1++;

            else if(e2 == nums[i]) cnt2++;

            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for(int i : nums){
            if(i == e1) cnt1++;
            else if(i == e2) cnt2++;
        }

        if(cnt1 > floor(nums.size()/3) && cnt2 > floor(nums.size()/3)) return {e1, e2};
        else if(cnt1 > floor(nums.size()/3)) return {e1};
        else if(cnt2 > floor(nums.size()/3)) return {e2};
        else return {};
        
    }
};