class Solution {
public:
    // bool isSafe(vector<string>& board, int row, int col, int n){
    //     for(int j = 0; j < col; j++){
    //         if(board[row][j] == 'Q') return false;
    //     }

    //     for(int i = row-1, j = col-1; i >= 0 && j >= 0; i-- , j--){
    //         if(board[i][j] == 'Q') return false;
    //     }

    //     for(int i = row+1, j = col-1; i < n && j >= 0; i++ , j--){
    //         if(board[i][j] == 'Q') return false;
    //     }

    //     return true;
    // }


    void solve(vector<vector<string>>& res, vector<string>& board, int col, int n, vector<int>& left, vector<int>& lowerLeft, vector<int>& upperLeft){
        if(col == n){
            res.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(left[row] == 0 && lowerLeft[col+row] == 0 && upperLeft[n-1 + col-row] == 0){
                left[row] = 1;
                lowerLeft[col+row] = 1;
                upperLeft[n-1 + col-row] = 1;

                board[row][col] = 'Q';

                solve(res, board, col+1, n, left, lowerLeft, upperLeft);

                left[row] = 0;
                lowerLeft[col+row] = 0;
                upperLeft[n-1 + col-row] = 0;

                board[row][col] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n, '.');
        vector<string> board(n, s);

        vector<int> left(n, 0);
        vector<int> lowerLeft(2*n-1, 0);
        vector<int> upperLeft(2*n-1, 0);
        

        solve(res, board, 0, n, left, lowerLeft, upperLeft);

        return res;
    }
};