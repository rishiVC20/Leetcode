class Solution {
    #define ll long long 
public:
    long long pickGifts(vector<int>& gifts, int k) {
        ll n=gifts.size();
        priority_queue<ll>pq;
        for(auto i:gifts){
            pq.push(i);
        }

        for(ll i=0; i<k; i++){
            ll tp=pq.top();
            pq.pop();
            ll m=floor(sqrt(tp));
            pq.push(m);
        }

        ll cn=0;
        while(!pq.empty()){
            cn += pq.top();
            pq.pop();
        }

        return cn;
    }
};