class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mp;
        int maxi=1;
        for(auto i:nums1){
            mp[i[0]]+=i[1];
            maxi=max(maxi,i[0]);
        }
        for(auto i:nums2){
            mp[i[0]]+=i[1];
            maxi=max(maxi,i[0]);
        }

        vector<vector<int>>v;
        // for(int i=1; i<=maxi; i++){
        //     if(mp.find(i)==mp.end()){
        //         v.push_back({i,0});
        //     }
        //     else{
        //         v.push_back({i,mp[i]});
        //     }
        // }
        for(auto i:mp){
            v.push_back({i.first,i.second});
        }

        return v;
    }
};