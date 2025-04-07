class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp;
        map<char,char>m1;
        for(int i=0; i<(int)s.size(); i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]] != t[i])
                    return false;
            }
            if(m1.find(t[i])!=m1.end()){
                if(m1[t[i]]!=s[i])
                    return false;
            }
            m1[t[i]]=s[i];
            mp[s[i]]=t[i];
        }

        return true;
    }
};