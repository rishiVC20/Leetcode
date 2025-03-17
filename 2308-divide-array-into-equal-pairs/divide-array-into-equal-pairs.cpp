class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int k=0;
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto i:mp){
            if(i.second&1)
                return false;
        }
        return true;
    }
};