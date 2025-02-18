class Solution {
public:
    bool f(string &s, string &pat){
        for(int i=0; i<pat.size(); i++){
            if(pat[i]=='I'){
                if(s[i]>s[i+1])
                    return false;
            }
            else{
                if(s[i]<s[i+1])
                    return false;
            }
        }

        return true;
    }
    string smallestNumber(string pattern) {
        int n=pattern.size();
        string ans="";
        for(int i=1; i<=n+1; i++){
            ans.push_back(i+'0');
        }

        string k=ans;
        while(!f(k,pattern)){
            next_permutation(k.begin(),k.end());
        }
        return k;
    }
};