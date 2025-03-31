class Solution {
    #define ll long long
public:
    long long putMarbles(vector<int>& weights, int k) {
        ll n=weights.size();
        priority_queue<tuple<ll,ll,ll>>pq;
        ll cp=weights[0]+weights[n-1];
        vector<ll>dp;
        for(ll i=1; i<n; i++){
            ll k=weights[i]+weights[i-1];
            dp.push_back(k);
            pq.push({k,i,i-1});
            pq.push({weights[i]*2,i,i});
        }
        sort(dp.begin(),dp.end());
        ll ans=0;
        for(ll i=0; i<k-1; i++){
            ans+=dp[n-2-i]-dp[i];
        }
        return ans;
        pq.push({weights[0]*2,0,0});
        // pq.push({weights[n-1]*2,n-1,n-1});
        // cout<<cp<<' ';
        set<ll>st;
        // st.insert(0),st.insert(n-1);
        ll gp=1;
        while(gp<k && !pq.empty()){
            tuple<ll,ll,ll>tp=pq.top();
            pq.pop();
            if (st.find(get<1>(tp))!=st.end() || st.find(get<2>(tp))!=st.end()){
                continue;
            }
            cp+=get<0>(tp);
            cout<<get<0>(tp)<<' '<<get<1>(tp)<<' '<<get<2>(tp)<<' ';
            st.insert(get<1>(tp)),st.insert(get<2>(tp));
            for(auto i:st){
                cout<<i<<' ';
            }
            cout<<endl;
            gp++;
        }
        // cout<<cp<<endl;
        ll mp=weights[0]+weights[n-1];
        gp=1;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pp;
        for(int i=1; i<n; i++){
            ll k=weights[i]+weights[i-1];
            pp.push({k,i,i-1});
            pp.push({weights[i]*2,i,i});
        }
        pp.push({weights[0]*2,0,0});
        // pp.push({weights[n-1],n-1,n-1});
        cout<<endl;
        set<ll>sp;
        // sp.insert(0),sp.insert(n-1);
        while(gp<k && !pp.empty()){
            tuple<ll,ll,ll>tp=pp.top();
            pp.pop();
            if (sp.find(get<1>(tp))!=sp.end() || sp.find(get<2>(tp))!=sp.end()){
                continue;
            }
            mp+=get<0>(tp);
            cout<<get<0>(tp)<<' '<<get<1>(tp)<<' '<<get<2>(tp)<<endl;
            sp.insert(get<1>(tp)),sp.insert(get<2>(tp));
            gp++;
        }
        cout<<cp<<' '<<mp<<' ';

        return abs(cp-mp);
    }
};