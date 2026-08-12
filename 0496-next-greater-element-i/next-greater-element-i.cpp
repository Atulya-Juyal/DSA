class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mp;
        stack<int> stk;

        for(int i = nums2.size()-1; i >= 0; i--){
            while(!stk.empty() && stk.top() < nums2[i]) stk.pop();

            if(stk.empty()) mp[nums2[i]] = -1;
            else mp[nums2[i]] = stk.top();

            stk.push(nums2[i]);
        }

        for(int i : nums1){
            res.push_back(mp[i]);
        }

        return res;
    }
};