class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int cn=INT_MAX;

        for(int i=l; i<=r; i++){
            int sum=0;
            for(int j=0; j<i; j++){
                sum += nums[j];
            }
            if(sum>0)
                cn=min(cn,sum);
            int j=0,k=i;
            while(k<nums.size()){
                sum += nums[k++];
                sum-=nums[j++];
                if(sum>0)
                    cn=min(cn,sum);
            }
        }

        if(cn==INT_MAX)
            return -1;


        return cn;    
    }
};