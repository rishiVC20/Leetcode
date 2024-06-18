class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m = worker.size();
        int n = profit.size();
        vector<int>a;
        vector<pair<int,int>>v;
        for (int i=0; i<n; i++)
        {
            // v[i].first = profit[i];
            // v[i].second = difficulty[i];
            v.push_back({profit[i],difficulty[i]});
        }
        sort(v.begin(),v.end(),[&](pair<int,int>a,pair<int,int>b){
            return a.second < b.second;
        });
        int j = 0;
        priority_queue<int>maxi;

        sort(worker.begin(),worker.end());
        int sum = 0;
        int best = 0;
        for (int i=0; i<m; i++)
        {
            while  (j<n && v[j].second<=worker[i]){
                // maxi.push(v[j].first);
                best = max(best,v[j].first);
                j++;
            }
            // if (!maxi.empty()){
            //     int k = maxi.top();
            //     maxi.pop();
            //     sum += k;
            //     // a.push_back(k);
            // }
            sum += best;
        }
        // int sum = accumulate(a.begin(),a.end(),0);

        return sum;
    }
};