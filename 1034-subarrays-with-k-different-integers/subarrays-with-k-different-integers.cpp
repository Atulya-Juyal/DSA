
class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        int left = 0, res = 0;
        unordered_map<int, int> freq;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            while (freq.size() > k) {
                freq[nums[left]]--;
                
                if (freq[nums[left]] == 0) freq.erase(nums[left]);
                
                left++;
            }

            res += (right - left + 1);
        }

        return res;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
};