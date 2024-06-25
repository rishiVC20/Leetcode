class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int f = false;
        int n = nums.size();
        int kp = -1;
        int z;
        for (int i=0; i<n; i++){
            z = kp;
            if (nums[i]==0){
                f = true;
                kp = 0;
            }
            else if (nums[i]==1 && f==true){
                kp = 1;
            }
            if (z != kp)
                ans++;
        }

        return ans;
    }
};