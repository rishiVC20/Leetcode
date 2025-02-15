class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        int cn=0;
        for (int i = 0; i < n; i++) {
            int p = -1, q = -1;
            if (i + k < n) {
                p=nums[i+k];
            }
            if(i-k>=0){
                q=nums[i-k];
            }
            if(nums[i]>p && nums[i]>q)
                cn+=nums[i];
        }

        return cn;
    }
};