class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0; i<n-k+1; i++){
            vector<int>p;
            for(int j=i; j<i+k; j++){
                p.push_back(nums[j]);
            }
            // for(auto i:p)
            //     cout<<i<<' ';
            // cout<<endl;    
            sort(p.begin(),p.end());
            map<int,int>mp;
            for(auto i:p)
                mp[i]++;
            vector<pair<int,int>>d;
            for(auto i:mp){
                d.push_back({i.first,i.second});
            }
            sort(d.begin(),d.end(),[&](pair<int,int>a,pair<int,int>b){
                if(a.second==b.second)
                    return a.first>b.first;
                return a.second>b.second;    
            });
            // for(auto i:d)
            //     cout<<i.first<<' '<<i.second<<"k ";
            // cout<<endl;    
            int cn=0;
            int m;
            if(d.size() > x)
                m=x;
            else
                m=d.size();    
            for(int j=0; j<m; j++){
                cn += (d[j].first*d[j].second);
            }
            ans.push_back(cn);
        }

        return ans;
    }
};