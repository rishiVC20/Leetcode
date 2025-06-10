class Solution {
public:
    int maxDifference(string s) {
        int maxi=0,mini=INT_MAX;
        map<int,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        for(auto i:mp){
            if(i.second&1){
                maxi=max(maxi,i.second);
            }
            else{
                mini=min(mini,i.second);
            }
        }

        // if(mini==INT_MAX){
        //     mini=0;
        // }
        return maxi-mini;
    }
};