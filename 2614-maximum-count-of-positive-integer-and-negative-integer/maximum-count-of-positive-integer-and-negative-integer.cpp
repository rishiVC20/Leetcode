class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int p1=0,p2=0;
        for(auto i:nums){
            p1+=(i>0);
            p2+=(i<0);
        }

        return max(p1,p2);
    }
};