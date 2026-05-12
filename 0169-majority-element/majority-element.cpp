class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int cnt = 0;

        for(int i : nums){
            if(cnt == 0){
                ele = i;
                cnt++;
                continue;
            }

            if(i == ele) cnt++;
            else cnt--;
        }

        return ele;
    }
};