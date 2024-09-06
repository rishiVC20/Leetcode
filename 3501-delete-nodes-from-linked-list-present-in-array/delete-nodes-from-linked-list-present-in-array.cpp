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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* p = new ListNode(0);
        ListNode* b=p;
        set<int>st;
        for(auto i:nums)
            st.insert(i);
        ListNode* q=head;
        while(q!=NULL){
            // cout<<'j'<<' ';
            int ll=q->val;
            if(st.find(ll) != st.end()){
                // cout<<'k';
                q=q->next;
                continue;
            }
            else{
                // cout<<'p'<<' ';
                b->next=q;
                b=b->next;
                q=q->next;
            }
            
        }   
        b->next=NULL; 
        return p->next;
    }
};