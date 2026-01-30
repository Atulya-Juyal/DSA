class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0;
        int cnt = 0;

        for(int i : nums){
            if(i == 1){
                cnt++;
                mx = max(mx, cnt);
                continue;
            }
            cnt = 0;
        }

        return mx;
    }
};