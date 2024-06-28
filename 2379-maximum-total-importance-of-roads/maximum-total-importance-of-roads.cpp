class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // vector<vector<>>
        map<long long,vector<long long>>mp;
        for (auto i:roads){
            long long p = i[0];
            long long q = i[1];
            mp[p].push_back(q);
            mp[q].push_back(p);
        }
        vector<pair<long long,long long>>v;
        for (auto i:mp){
            // long long p = i.first;
            // cout<<i.first<<' '<<i.second.size()<<endl;
            v.push_back({i.first,i.second.size()});
        }
        sort(v.begin(),v.end(),[&](pair<long long,long long>a,pair<long long,long long>b){
            return a.second > b.second;
        });
        for (auto i:v){
            cout<<i.first<<' '<<i.second<<endl;
        }
        vector<long long>a(n,0);
        long long k = 0;
        long long m = n;
        for (auto i:v){
            // long long q = v[k].second.size();
            long long q = i.second;
            if (q > 0){
                long long z = i.first;
                cout<<z<<' ';
                a[z] = m;
                m--;
            }
            // k++;
        }
        // for (auto i:a){
        //     cout<<i<<' ';
        // }
        long long sum = 0;
        for (auto i:roads){
            long long p = i[0];
            long long q = i[1];
            sum += (a[p]+a[q]);
        }
        return sum;
    }
};