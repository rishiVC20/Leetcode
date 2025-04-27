class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cn=0;
        int n=nums.size();
        for(int i=0; i<n-2; i++){
            int p=nums[i]+nums[i+2];
            int m=(nums[i+1]/2);
            if(p*2==nums[i+1])
                cn++;
        }

        return cn;
    }
};