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
    ListNode* reverseList(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;

        return newHead;
    }


    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* h1 = head;
        ListNode* h2 = slow->next;
        slow->next = nullptr;

        h2 = reverseList(h2);

        int res = 0;
        while(h1 != nullptr){
            res = max(res, h1->val + h2->val);
            h1 = h1->next;
            h2 = h2->next;
        }

        return res;
    }
};