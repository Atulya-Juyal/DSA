class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int r = 0;

        for(int i = 0; i < n; i++){
            r ^= nums[i];
            r ^= i+1;
        }

        int bitNo = 0;
        while(true){
            if((r & (1 << bitNo)) != 0) break; 
            bitNo++;
        }

        int z = 0;
        int o = 0;
        for(int i : nums){
            if((i & (1 << bitNo)) == 0) z ^= i;
            else o ^= i;
        }
        for(int i = 1; i <= n; i++){
            if((i & (1 << bitNo)) == 0) z ^= i;
            else o ^= i;
        }

        int cnt = 0;
        for(int i : nums){
            if(z == i) return {z, o};
        }
        return {o, z};
    }
};