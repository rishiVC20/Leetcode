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
    ListNode* reverseIt(ListNode* &head)
    {
        ListNode* curr = head;
        ListNode* forward = NULL;
        ListNode* prev = NULL;
        while (curr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* l1 = reverseIt(head);
        ListNode* l2 = l1;
        int carr = 0;
        ListNode* temp = l1;
        while (temp)
        {
            if (l2 != NULL){
                temp->val = temp->val+l2->val+carr;
                l2 = l2->next;
            }

            carr = 0;
            if (temp->val >= 10){
                carr = 1;
                temp->val = temp->val - 10;
            }
            temp = temp->next;
        }

        if (carr == 1)
        {
            ListNode* root = new ListNode(1);
            temp = l1;
            while (temp->next != NULL){
                temp = temp->next;
            }

            temp->next = root;
        }

        return reverseIt(l1);
    }
};