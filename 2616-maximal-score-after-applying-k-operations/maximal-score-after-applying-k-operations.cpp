class Solution {
    #define ll long long
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<ll>q;
        ll n=nums.size();
        for(ll i=0; i<n; i++){
            q.push(nums[i]);
        }
        ll cn=0;
        for(ll i=0; i<k; i++){
            ll p=q.top();
            q.pop();
            cn += p;
            ll m=p/3;
            if(p%3 != 0)
                m++;
            // cout<<m<<' ';
            q.push(m);
        }

        return cn;
    }
};