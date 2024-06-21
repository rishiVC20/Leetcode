class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        vector<pair<int,int>>v;
        int n = customers.size();
        for (int i=0; i<n; i++){
            // v[i].first = customers[i];
            // v[i].second = grumpy[i];
            v.push_back({customers[i],grumpy[i]});
        }
        if (accumulate(grumpy.begin(),grumpy.end(),0)==0){
            return accumulate(customers.begin(),customers.end(),0);
        }

        int curr = 0;
        int maxi = 0;
        int x,y;
        int cc;
        // for (int i=0; i<n; i++){
        //     cc = maxi;
        //     if (grumpy[i]==1){
        //         curr++;
        //     }
        //     else
        //         curr = 0;
        //     maxi = max(maxi,curr);  
        //     if (cc!=maxi){
        //         // x
        //     }      
        // }
        int sum = 0;
        for (int i=0; i<n; i++){
            if (v[i].second == 0)
                sum += v[i].first;
        }
        int ans = sum;
        // int cp = su
        int k = minutes;
        for (int i=0; i<=n-k; i++){
            int cp = sum;
            int g = i;
            for (int j=0; j<k; j++){
                if (v[g].second==1)
                    cp += v[g].first;
                g++;    
            }
            ans = max(ans,cp);
        }

        return ans;
    }
};