class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<int>a,b;
        int n = arrays.size();
        vector<pair<int,int>>v;
        for (auto i:arrays){
            int n=i.size();
            int k1=i[0];
            int k2=i[n-1];
            a.push_back(k1);
            b.push_back(k2);
            v.push_back({k1,k2});
        }
        for (auto i:a)
            cout<<i<<' ';
        cout<<endl;
        for (auto i:b)
            cout<<i<<' ';    
        // sort(a.begin(),a.end());
        // sort(b.begin(),b.end());
        bool f=true;
        int j=-1;
        int gg=INT_MAX;
        for (int i=0; i<n; i++){
            if (a[i]<gg){
                gg=a[i];
                j=i;
            }
        }
        int y=-1;
        int hh=INT_MIN;
        for (int i=0; i<n; i++){
            if (b[i]>hh){
                hh=b[i];
                y=i;
            }
        }
        int sum1=0;
        for (int i=0; i<n; i++){
            if (i==j)
                continue;
            sum1=max(sum1,abs(gg-b[i]));    
        }
        int sum2=0;
        for (int i=0; i<n; i++){
            if (i==y)
                continue;
            sum2 = max(sum2,abs(hh-a[i]));    
        }
        int maxi = max(sum1,sum2);

        return maxi;
    }
};