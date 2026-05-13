class Solution {
public:
    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> resRow;
        resRow.push_back(ans);

        for(int col = 1; col < row; col++){
            ans *= (row - col);
            ans /= col;

            resRow.push_back(ans);
        }

        return resRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> temp;

        for(int i = 1; i <= numRows; i++){
            temp = generateRow(i);
            res.push_back(temp);
        }

        return res;
    }
};