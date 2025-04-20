class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int>mp;
        for(auto i:answers){
            mp[i]++;
        }

        int cn=0;
        for(auto i:mp){
            int r=i.first;
            int t=i.second/(r+1)+(i.second%(r+1)!=0);
            cn+=t*(r+1);
        }

        return cn;
    }
};