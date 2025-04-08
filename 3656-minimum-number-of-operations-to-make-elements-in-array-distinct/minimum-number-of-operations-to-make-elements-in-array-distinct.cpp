class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>mp;

        for(auto i:nums){
            mp[i]++;
        }

        int n=nums.size();
        int cn=0;
        for(int i=0; i<nums.size(); i+=3){
            bool f=true;
            for(int j=i; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[j]==nums[k]){
                        f=false;
                        cn++;
                        break;
                    }
                }
                if(!f)
                    break;
            }
            if(f)
                break;
        }

        return cn;
    }
};