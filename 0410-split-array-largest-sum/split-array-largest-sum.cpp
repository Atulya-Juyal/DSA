class Solution {
public:
    int possible(vector<int>& nums, int d){
        int cnt = 1;
        int sum = 0;

        for(int i : nums){
            if(sum + i <= d){
                sum += i;
            }
            else{
                cnt++;
                sum = i;
            }
        }

        return cnt;
    }


    int splitArray(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        for(int i : nums){
            l = max(l, i);
            r += i;
        }

        while(l <= r){
            int m = l + (r-l)/2;

            if(possible(nums, m) > k) l = m + 1;
            else r = m - 1;
        }

        return l;
    }
};