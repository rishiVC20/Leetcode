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
        ListNode* p=NULL;
        ListNode* q=NULL;
        ListNode* r=head;
        while(r != NULL){
            p = r->next;
            r->next = q;
            q = r;
            r = p;
        }

        return q;
    }
};