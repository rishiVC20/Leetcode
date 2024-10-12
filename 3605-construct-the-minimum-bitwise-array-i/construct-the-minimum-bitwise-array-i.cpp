class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=*max_element(nums.begin(),nums.end());
        for(int i=1; i<=maxi; i++){
            int k=i|(i+1);
            // pre[i]=k;
            if(mp.find(k) == mp.end()){
                mp[k]=i;
            }
        }
        // for(int i=1; i<=10; i++)
        //     cout<<pre[i]<<' ';
        vector<int>a;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0){
                a.push_back(-1);
                continue;
            }
            // int k=check(nums[i],pre);
            if(mp.find(nums[i]) != mp.end())
                a.push_back(mp[nums[i]]);
            else
                a.push_back(-1);    
        }

        return a;
    }
};