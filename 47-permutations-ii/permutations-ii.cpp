class Solution {
public:
    string findStr(vector<int>&v){
        string s="";
        for(auto i:v){
            s.push_back(i);
        }
        return s;
    }
    bool check(vector<int>&v,map<int,int>&m1){
        map<int,int>m;
        for(auto i:v){
            m[i]++;
            if(m[i]>m1[i]){
                return false;
            }
        }
        return true;
    }
    void solve(vector<vector<int>> &ans, vector<int>&nums, map<string,int>&mp,vector<int>&v, map<int,int>&m1){
        // if(v.size()>nums.size())
        //     return;
        if(v.size()==nums.size()){
            // string s=findStr(v);
            // if(mp.find(s)==mp.end() && check(v,m1)){
            //     mp[s]++;
                ans.push_back(v);
            // }
            return;
        }
        
        for(auto i:m1){
            if(i.second==0)
                continue;
            m1[i.first]--;    
            v.push_back(i.first);
            solve(ans,nums,mp,v,m1);
            v.pop_back();
            m1[i.first]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        map<string,int>mp;
        map<int,int>m1;
        for(auto i:nums){
            m1[i]++;
        }
        solve(ans,nums,mp,v,m1);

        return ans;
    }
};