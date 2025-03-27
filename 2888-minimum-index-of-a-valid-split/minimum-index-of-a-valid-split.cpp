class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>mp;
        int mk=0;
        int ind=0;
        for(auto i:nums){
            mp[i]++;
            if(mp[i]>ind){
                mk=i;
                ind=mp[i];
            }
        }

        int n=nums.size();
        int ans=-1;
        int cd=0;
        for(int i=0; i<n; i++){
            if(nums[i]==mk){
                cd++;
                int s1=i+1,s2=n-i-1;
                int dp=ind-cd;
                // cout<<i<<' '<<cd<<' '<<dp<<endl;
                if(cd>(s1/2) && dp>(s2/2)){
                    ans=i;
                    break;
                }
            }
        }

        return ans;
    }
};