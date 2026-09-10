/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> solve(TreeNode* root, int& res){
        if(root == nullptr) return {0, 0};
        
        pair<int, int> left = solve(root->left, res);
        pair<int, int> right = solve(root->right, res);

        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;
        
        if(sum / cnt == root->val) res++;

        return {sum, cnt};
    }


    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        solve(root, res);
        return res;
    }
};