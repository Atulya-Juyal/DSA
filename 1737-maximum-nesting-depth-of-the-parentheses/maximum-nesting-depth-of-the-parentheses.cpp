class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxDepth = 0;

        for(auto i : s){
            if(i == '('){
                depth++;
                maxDepth = max(depth, maxDepth);
            }
            else if(i == ')') depth--;
        }

        return maxDepth;
    }
};