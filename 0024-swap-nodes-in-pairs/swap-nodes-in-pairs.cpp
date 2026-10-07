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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        
        ListNode* it = head;
        ListNode* newHead = head->next;

        while(it && it->next){
            ListNode* first = it;
            ListNode* second = it->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = it;
            it = it->next;
        }

        return newHead;

    }
};