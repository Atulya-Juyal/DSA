/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* it = head;

        while(it != nullptr){
            if(it->val != INT_MAX){
                it->val = INT_MAX;
                it = it->next;
            }
            else return true;;
        }

        return false;
    }
};