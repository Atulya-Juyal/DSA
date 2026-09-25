class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> pre(n, INT_MIN);
        vector<int> suf(n, INT_MIN);

        for(int i = 0; i < n; i++){
            if(i == 0) pre[i] = height[i];
            else pre[i] = max(pre[i-1], height[i]);
        }

        for(int i = n-1; i >= 0; i--){
            if(i == n-1) suf[i] = height[i];
            else suf[i] = max(suf[i+1], height[i]);
        }

        int res = 0;

        for(int i = 0; i < n; i++){
            res += min(pre[i], suf[i]) - height[i];
        }

        return res;
    }
};