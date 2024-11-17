class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>x,y;
        // sort(queries.begin(),queries.end(),[](const vector<int>&a, const vector<int>&b){
        //     if(a[0]==b[0])
        //         return a[1]<b[1];
        //     return a[0]<b[0];
        // });

        for(auto i:queries){
            x.push_back(i[0]);
            y.push_back(i[1]);
            // cout<<i[0]<<' '<<i[1]<<endl;
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        cout<<endl;
        for(int i=0; i<n; i++){
            int p=upper_bound(x.begin(),x.end(),i)-x.begin();
            p--;
            int q=lower_bound(y.begin(),y.begin()+p,i)-y.begin();
            // cout<<p<<' '<<q<<endl;
            int cn=p-q+1;
            if(cn < nums[i])
                return false;
        }

        return true;
    }
};