class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int s1 = 0;
        int s2 = 0;
        int s3 = 0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            if (nums[i]%2==1)
                s1++;
            if (nums[i]%2==0)
                s2++;    
        }
        bool f = false;
        for (int i=0; i<n; i++){
            if (nums[i]%2==0 && !f){
                s3++;
                f = !f;
            }
            if (nums[i]%2==1 && f){
                s3++;
                f = !f;
            }
        }
        int s4 = 0;
        f = false;
        for (int i=0; i<n; i++){
            if (nums[i]%2==1 && !f){
                s4++;
                f = !f;
            }
            if (nums[i]%2==0 && f){
                s4++;
                f = !f;
            }
        } 

        return max(s1,max(s2,max(s3,s4)));
    }
};