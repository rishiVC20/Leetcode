class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n);
        prefix[n-1]=nums[n-1];

        for(int i=n-2; i>=0; i--){
            prefix[i]=max(nums[i],prefix[i+1]);
        }

        int ans=-1;
        for(int i=0; i<n; i++){
            if(prefix[i]>nums[i]){
                ans=max(ans,prefix[i]-nums[i]);
            }
        }

        return ans;
    }
};