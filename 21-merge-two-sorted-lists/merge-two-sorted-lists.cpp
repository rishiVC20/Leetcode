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
    ListNode* sortedList(vector<int>&arr){
        if(arr.size()==0)
            return NULL;
        sort(arr.begin(),arr.end());
        long long i=0;
        ListNode* g = new ListNode(arr[0]);
        ListNode* j=g;
        for(int i=1; i<arr.size(); i++){
            ListNode* kk = new ListNode(arr[i]);
            j->next = kk;
            j = j->next;
        }

        return g;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>arr;
        ListNode* p=list1;
        while(p!=NULL){
            int k=p->val;
            arr.push_back(k);
            p=p->next;
        }
        p=list2;
        while(p!=NULL){
            int k=p->val;
            arr.push_back(k);
            p=p->next;
        }
        return sortedList(arr);
    }
};