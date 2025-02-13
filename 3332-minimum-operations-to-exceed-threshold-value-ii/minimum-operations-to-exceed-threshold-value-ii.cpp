class Solution {
    #define ll long long
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>>pq;

        for(auto i:nums){
            pq.push((int)i);
        }

        int op=0;
        while(!pq.empty()){
            ll t=pq.top();
            if(t>=k)
                return op;
            ll m1=pq.top();
            pq.pop();
            ll m2=pq.top();
            pq.pop();
            ll q=min(m1,m2)*2+max(m1,m2);
            pq.push(q);
            op++;
        }

        return -1;
    }
};