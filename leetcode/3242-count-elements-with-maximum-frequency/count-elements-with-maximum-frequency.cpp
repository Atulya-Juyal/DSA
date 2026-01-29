class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
        
        int max = 0;
        for(auto it : mp){
            if(it.second > max) max = it.second;
        }

        int cnt = 0;
        for(auto it : mp){
            if(it.second == max) cnt++;
        }

        return cnt * max;
    }
};