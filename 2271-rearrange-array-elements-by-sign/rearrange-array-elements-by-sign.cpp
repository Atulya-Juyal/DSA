class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p;
        vector<int> n;

        for(int i : nums){
            if(i > 0) p.push_back(i);
            else n.push_back(i);
        }

        int pi = 0;
        int ni = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(i%2 == 0){
                nums[i] = p[pi];
                pi++;
            }
            else{
                nums[i] = n[ni];
                ni++;
            }
        }

        return nums;
    }
};