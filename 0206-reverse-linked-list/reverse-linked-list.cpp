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
    ListNode* reverseList(ListNode* head) {
        ListNode* it = head;
        ListNode* back = nullptr;
        
        while(it != nullptr){
            ListNode* front = it->next;
            it->next = back;
            back = it;
            it = front;
        }

        return back;
    }
};