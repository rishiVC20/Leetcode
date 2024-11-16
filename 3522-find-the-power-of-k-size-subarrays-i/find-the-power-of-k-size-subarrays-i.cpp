class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1)
            return nums;
        vector<int>ans;    
        int p=1;
        int j=-1;
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1] && abs(nums[i]-nums[i-1])==1){
                p++;
                if(p>k)
                    p--;
            }
            else{
                p=1;
            }
            if(i>=k-1){
                if(p==k)
                    ans.push_back(nums[i]);
                else
                    ans.push_back(-1);    
            }
        }  

        return ans;
    }
};