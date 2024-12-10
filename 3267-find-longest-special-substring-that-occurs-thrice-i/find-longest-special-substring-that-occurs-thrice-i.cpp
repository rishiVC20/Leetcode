class Solution {
public:
    int maximumLength(string s) {
        map<string,int>mp;

        int n=s.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(s[i]==s[j]){
                    string k=s.substr(i,j-i+1);
                    mp[k]++;
                }
                else{
                    break;
                }
            }
        }

        int cn=0;
        for(auto i:mp){
            if(i.second >= 3){
                string dd=i.first;
                int m=dd.size();
                cn=max(cn,m);
            }
        }

        if(cn==0)
            return -1;

        return cn;    
    }
};