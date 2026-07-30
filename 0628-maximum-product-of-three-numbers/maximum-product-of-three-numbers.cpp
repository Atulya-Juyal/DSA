class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int h1 = INT_MIN;
        int h2 = INT_MIN;
        int h3 = INT_MIN;

        int l1 = INT_MAX;
        int l2 = INT_MAX;

        for(int i : nums){
            if(i > h1){
                h3 = h2;
                h2 = h1;
                h1 = i;
            }
            else if(i > h2){
                h3 = h2;
                h2 = i;
            }
            else if(i > h3){
                h3 = i;
            }

            if(i < l1){
                l2 = l1;
                l1 = i;
            }
            else if(i < l2){
                l2 = i;
            }
        }

        return max(h1 * h2 * h3, h1 * l1 * l2);

    }
};