class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        map<int,vector<int>>mp;
        int cn=0;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])!=mp.end()){
                vector<int>p=mp[nums[i]];
                for(int j=0; j<p.size(); j++){
                    if((p[j]*(i))%k==0){
                        // cout<<i+1<<' '<<j<<' ';
                        cn++;
                    }
                }
            }
            mp[nums[i]].push_back(i);
        }

        return cn;

    }
};