class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        for(int i=0; i<n; i++){
            colors.push_back(colors[i]);
        }

        vector<int>a;
        int cur=1;
        for(int i=1; i<=n+k-2; i++){
            if(colors[i]!=colors[i-1]){
                cur++;
            }
            else if(cur>1){
                a.push_back(cur);
                cur=1;
            }
        }
        if(cur>1){
            a.push_back(cur);
        }

        int ans=0;
        for(auto i:a){
            cout<<i<<' ';
            int p=i-k+1;
            if(p>0){
                ans+=p;
            }
        }

        return ans;
    }
};