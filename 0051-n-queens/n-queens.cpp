class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'Q'){
                    if(i == row || abs(row-i) == abs(col-j)) return false;
                }
            }
        }

        return true;
    }


    void solve(vector<vector<string>>& res, vector<string>& board, int col, int n){
        if(col == n){
            res.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(board, row, col, n)){
                board[row][col] = 'Q';
                solve(res, board, col+1, n);
                board[row][col] = '.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n, '.');
        vector<string> board(n, s);

        solve(res, board, 0, n);

        return res;
    }
};