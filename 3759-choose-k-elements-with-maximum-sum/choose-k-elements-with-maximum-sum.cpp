class Solution {
    #define ll long long
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<ll,ll>>v;
        ll n=nums1.size();
        for(ll i=0; i<n; i++){
            v.push_back({(ll)nums1[i],i});
        }

        sort(v.begin(),v.end(),[&](pair<ll,ll>&a, pair<ll,ll>&b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first<b.first;
        });

        vector<ll>a(n);
        for(ll i=0; i<n; i++){
            a[v[i].second]=nums2[v[i].second];
        }
        // for(auto i:v){
        //     cout<<nums2[i.second]<<' ';
        // }
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        ll sum=nums2[v[0].second];
        vector<ll>ans(n);
        ans[v[0].second]=0;
        pq.push(nums2[v[0].second]);
        for(ll i=1; i<n; i++){
            
            if(nums1[v[i].second]==nums1[v[i-1].second]){
                ans[v[i].second]=ans[v[i-1].second];
                sum+=nums2[v[i].second];
                pq.push(nums2[v[i].second]);
                if(pq.size()>k){
                    sum-=pq.top();
                    pq.pop();
                }
                continue;
            }
            ans[v[i].second]=sum;
            sum+=nums2[v[i].second];
            pq.push(nums2[v[i].second]);
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            
        }

        return ans;
    }
};