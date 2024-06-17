class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>>v(n);
        for (int i=0; i<n; i++)
        {
            v[i].first = profits[i];
            v[i].second = capital[i];
        }
        vector<bool>visited(n,false);
        // sort(v.begin(),v.end(),[&](pair<int,int>a,pair<int,int>b){
        //     return a.first < b.first;
        // });
        sort(v.begin(),v.end(),[&](pair<int,int>a,pair<int,int>b){
            return a.second < b.second;
        });
        // for (int i=0; i<k; i++)
        // {
        vector<int>kp(n);
        for (int i=0; i<n; i++){
            kp[i] = v[i].second;
        }
        // for (auto i:v)
        //     cout<<i.first<<' ';
        priority_queue<int> maxHeap;
        
        int j = 0;
        for (int i=0; i<k; i++)
        {
            while (j<n && v[j].second<=w){
                maxHeap.push(v[j].first);
                j++;
            }

            if (maxHeap.empty())
                break;
            w += maxHeap.top();
            maxHeap.pop();
        }
        // }

        return w;
    }
};