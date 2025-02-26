class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0;
        int cur=0;
        int n=nums.size();

        for(int i=0; i<n; i++){
            cur+=nums[i];
            sum=max(sum,abs(cur));
            if(cur<0){
                cur=0;
            }
        }
        cur=0;
        for(int i=0; i<n; i++){
            cur+=nums[i];
            sum=max(sum,abs(cur));
            if(cur>0)
                cur=0;
        }

        return sum;
    }
};