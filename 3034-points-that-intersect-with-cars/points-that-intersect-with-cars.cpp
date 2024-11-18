class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),[](const vector<int>&a, const vector<int>&b){
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]<b[0];    
        });

        map<int,int>mp;
        int maxi=0;
        for(auto i:nums){
            cout<<i[0]<<" "<<i[1]<<endl;
            mp[i[0]]++;
            mp[i[1]+1]--;
            maxi=max(maxi,max(i[0],i[1]));
        }
        int cn=0;
        int ans=0;
        for(int i=1; i<=maxi+1; i++){
            if(mp.find(i) != mp.end())
                cn += mp[i];
            if(cn>0)
                ans++;    
        }

        return ans;

    }
};