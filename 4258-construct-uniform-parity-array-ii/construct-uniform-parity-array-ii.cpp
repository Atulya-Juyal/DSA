class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = INT_MAX;
        int max_odd = INT_MIN;

        int min_even = INT_MAX;
        int max_even = INT_MAX;

        int odd = 0;
        int even = 0;

        for(int i : nums1){
            if(i % 2 == 0){
                min_even = min(min_even, i);
                max_even = max(max_even, i);
                even++;
            }
            else{
                max_odd = max(max_odd, i);
                min_odd = min(min_odd, i);
                odd++;
            }
        }

        if(odd == 0 || even == 0) return true;
        else if((odd == 1 && even == 1) && (max_odd < min_even)) return true;
        else if(min_odd < min_even) return true;

        return false;

    }
};