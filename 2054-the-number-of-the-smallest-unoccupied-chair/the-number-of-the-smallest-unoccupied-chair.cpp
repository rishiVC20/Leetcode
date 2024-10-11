class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<pair<int,pair<int,int>>>v;
        for(int i=0; i<n; i++){
            int a=times[i][0];
            int b=times[i][1];
            int c=i;
            v.push_back({a,{b,c}});
        }
        sort(v.begin(),v.end());

        vector<int>ans(n,-1);
        for(int i=0; i<n; i++){
            int a=v[i].first;
            int b=v[i].second.first;
            int c=v[i].second.second;
            for(int j=0; j<n; j++){
                if(ans[j]<=a){
                    ans[j]=b;
                    if(c==targetFriend)
                        return j;
                    break;    
                }
            }
        }

        return 0;
    }
};