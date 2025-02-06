class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int cn=0;
        int n=nums.size();
        map<int,int>mp;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int k=nums[i]*nums[j];
                mp[k]++;

            }
        }

        for(auto i:mp){
            if(i.second>=2){
                cn+=(i.second)*(i.second-1)/2;
            }
        }
        cn*=8;
        return cn;
    }
};