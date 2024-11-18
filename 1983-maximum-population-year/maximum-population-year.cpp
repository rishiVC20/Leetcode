class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>mp;
        for(auto i:logs){
            mp[i[0]]++;
            mp[i[1]]--;
        }
        int cn=0;
        int maxp=0;
        int ans;
        for(auto i:mp){
            // cout<<i.first<<' ';
            
            cn += i.second;
            if(cn>maxp){
                maxp=cn;
                ans=i.first;
            }
        }

        return ans;
    }
};