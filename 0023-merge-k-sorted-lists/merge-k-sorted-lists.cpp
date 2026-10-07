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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* it = &dummy;

        bool exists = false;
        for(auto i : lists){
            if(i){
                exists = true;
                break;
            }
        }

        while(exists){
            int mini = INT_MAX;
            ListNode* cur;
            int idx = -1;

            for(int i = 0; i < lists.size(); i++){
                if(lists[i] == nullptr) continue;

                if(lists[i]->val < mini){
                    mini = lists[i]->val;
                    cur = lists[i];
                    idx = i;
                }
            }

            it->next = cur;
            it = it->next;
            lists[idx] = cur->next;

            exists = false;
            for(auto i : lists){
                if(i){
                    exists = true;
                    break;
                }
            }

        }

        return dummy.next;
    }
};