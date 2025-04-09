class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mini=*min_element(nums.begin(),nums.end());
        if(mini<k){
            return -1;
        }
        int p=0;
        map<int,int>mp;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]>k){
                mp[nums[i]]++;
            }
        }

        return (int)mp.size();
    }
};