class Solution {
public:
    void f(int n, string &ans, map<string,int> &mp, string &z){
        if(z.size()>=n){
            // cout<<z<<' ';
            if(mp.find(z)==mp.end()){
                ans=z;
                
            }
            return;
        }

        z.push_back('1');
        f(n,ans,mp,z);
        z.pop_back();
        z.push_back('0');
        f(n,ans,mp,z);
        // f(n,ans,mp,z);
        z.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        map<string,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        string ans="",z="";
        f(n,ans,mp,z);

        return ans;
    }
};