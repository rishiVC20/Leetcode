class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        vector<int>p(n);
        int k=0;
        int tp=0;
        for(int i=0; i<n; i++){
            if(nums[i]!=val){
                p[k]=nums[i];
                k++;
            }
            else{
                tp++;
            }
        }
        nums=p;
        return n-tp;
        // for(int i=0; i<k; )
    }
};