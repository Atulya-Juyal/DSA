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
    ListNode* findKthNode(ListNode* head, int k){
        int cnt = 1;
        ListNode* kth = head;
        while(cnt < k){
            if(kth->next  == nullptr) return nullptr;
            kth = kth->next;
            cnt++;
        }
        return kth;
    }

    ListNode* reverseList(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* nex;
        ListNode* kth;

        while(temp != nullptr){
            kth = findKthNode(temp, k);

            if(kth == nullptr) break;

            nex = kth->next;
            kth->next = nullptr;

            kth = reverseList(temp);

            pre->next = kth;

            temp->next = nex;
            pre = temp;
            temp = temp->next;
        }

        return dummy->next;
    }
};