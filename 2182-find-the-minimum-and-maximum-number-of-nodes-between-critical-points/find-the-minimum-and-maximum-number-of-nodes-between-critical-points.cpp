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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        ListNode* pre=head;
        ListNode* cur=head->next;
        ListNode* forward=cur->next;
        if (forward==NULL)
            return {-1,-1};
        int k = 2;    
        while (forward != NULL)
        {
            int p = pre->val;
            int q = cur->val;
            int r = forward->val;
            // cout<<k<<' ';
            if (q>p && q>r)
                ans.push_back(k);
            if (q<p && q<r)
                ans.push_back(k);    
            pre = cur;
            cur = forward;
            forward = forward->next;
            k++;
        }    
        if (ans.size() < 2)
            return {-1,-1};
        for (auto i:ans)
            cout<<i<<' ';
        int a = ans[ans.size()-1] - ans[0];
        int mini = INT_MAX;
        for(int i=1; i<ans.size(); i++){
            mini = min(ans[i]-ans[i-1],mini);
        }

        return {mini,a};
    }
};