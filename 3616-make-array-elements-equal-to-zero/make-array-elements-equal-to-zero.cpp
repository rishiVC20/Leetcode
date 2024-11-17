class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n),suf(n);

        pre[0]=nums[0],suf[n-1]=nums[n-1];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1]+nums[i];
        }
        for(int i=n-2; i>=0; i--){
            suf[i]=suf[i+1]+nums[i];
        }
        int cn=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                int p=suf[i],q=pre[i];
                if(p-q == 0)
                    cn+=2;
                else if(abs(p-q) == 1)
                    cn++;    
            }
        }

        return cn;
    }
};