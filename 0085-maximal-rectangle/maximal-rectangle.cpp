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


    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> ma(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') ma[i][j] = 1;
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(ma[i][j] != 0) ma[i][j] += ma[i-1][j];
            }
        }

        int res = 0;

        for(int i = 0; i < n; i++){
            res = max(res, largestRectangleArea(ma[i]));
        }

        return res;
    }
};