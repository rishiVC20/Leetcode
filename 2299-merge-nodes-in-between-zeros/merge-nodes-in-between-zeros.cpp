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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode* ans = new ListNode();
        ListNode* see = ans;
        // ListNode* u = see;
        // while (head != NULL){
        //     // u = ans;
            head = head->next;
            while (head!=NULL){
                if (head->val==0){
                    see->next = new ListNode(sum);
                    see = see->next;
                    sum = 0;
                    // head= head->next;
                }
                sum += head->val;
                head = head->next;
            }
            // cout<<sum<<' ';
            // ListNode* point = new ListNode(sum);
            // ans->next = point;
        // } 
        // see = see->next;
        return ans->next;
    }
};