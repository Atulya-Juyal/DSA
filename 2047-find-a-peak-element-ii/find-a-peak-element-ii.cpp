class Solution {
public:
    int findMaxIndex(vector<vector<int>>& mat, int n, int col){
        int idx = -1;
        int maxVal = -1;

        for(int i = 0; i < n; i++){
            if(mat[i][col] > maxVal){
                maxVal = mat[i][col];
                idx = i;
            }
        }

        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;

        while(low <= high){
            int col = low + (high - low) / 2; 
            int row = findMaxIndex(mat, n, col);

            int left = col-1 >= 0 ? mat[row][col-1] : -1;
            int right = col+1 < m ? mat[row][col+1] : -1;

            int i = mat[row][col];

            if(left < i && i > right){
                return {row, col};
            }
            else if(left > i){
                high = col - 1;
            }
            else{
                low = col + 1;
            }
        }

        return {0, 0};
    }
};