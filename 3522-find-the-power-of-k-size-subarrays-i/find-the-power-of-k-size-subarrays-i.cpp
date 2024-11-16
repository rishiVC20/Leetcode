class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        int i=-1,j=-1;
        vector<int>ans;
        for(int i=0; i<=n-k; i++){
            bool f=true;
            int p;
            for(int j=i; j<i+k-1; j++){
                // cout<<nums[j]<<' ';
                if(nums[j]>=nums[j+1] || (abs(nums[j]-nums[j+1])!=1)){
                    f=false;
                    // break;
                }
                p=nums[j];
            }
            cout<<endl;
            if(f)
                ans.push_back(nums[i+k-1]);
            else{
                ans.push_back(-1);
            }    
        }

        return ans;
    }
};