class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int m=pref.size();
        int cn=0;
        for(int i=0; i<words.size(); i++){
            string s=words[i];
            if(s.size()<m)
                continue;
            string f=s.substr(0,m);
            cn += (f==pref);
        }      

        return cn;
    }
};