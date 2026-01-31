class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int, int> mp;
        // for(int i : nums) mp[i]++;

        // for(auto i : mp){
        //     if(i.second > nums.size()/2) return i.first;
        // }

        // return 0;

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