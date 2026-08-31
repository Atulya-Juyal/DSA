/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> crit;
        
        ListNode* back = head;
        ListNode* it = (back != nullptr) ? back->next : nullptr;
        ListNode* front = (it != nullptr) ? it->next : nullptr;

        int i = 1;

        while(back != nullptr && front != nullptr){
            if(back->val > it->val && it->val < front->val) crit.push_back(i);
            else if(back->val < it->val && it->val > front->val) crit.push_back(i);

            i++;

            back = it;
            it = front;
            front = front->next;
        }

        if(crit.size() < 2) return {-1, -1};

        int mini = INT_MAX;
        int maxi = crit[crit.size()-1] - crit[0];

        for(int i = 0; i < crit.size()-1; i++){
            mini = min(mini, crit[i+1]-crit[i]);
        }

        return {mini, maxi};
    }
};