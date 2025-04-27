class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        string com="";
        int cn=0;
        map<string,int>mp;
        for(auto i:responses){
            set<string>st;
            for(auto j:i){
                st.insert(j);
            }
            for(auto j:st){
                mp[j]++;
                // cout<<j<<' ';
                if(mp[j]>cn){
                    cn=mp[j];
                    com=j;
                }
                else if(mp[j]==cn && j<com){
                    com=j;
                }
            }
        }

        return com;

    }
};