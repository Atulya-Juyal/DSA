class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        stack<int> stk;

        for(int i = 0; i < n; i++){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                int ele = stk.top();
                stk.pop();

                int nse = i;
                int pse = stk.empty() ? -1 : stk.top();

                res = max(res, (nse - pse - 1) * heights[ele]);
            }

            stk.push(i);
        }

        while(!stk.empty()){
            int ele = stk.top();
            stk.pop();

            int nse = n;
            int pse = stk.empty() ? -1 : stk.top();

            res = max(res, (nse - pse - 1) * heights[ele]);
        }

        return res;
    }
};