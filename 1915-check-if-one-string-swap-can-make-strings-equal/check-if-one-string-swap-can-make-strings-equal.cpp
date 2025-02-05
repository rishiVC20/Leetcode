class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cn=0;
        int j1=-1,j2=-1;
        for(int i=0; i<s1.size(); i++){
            cn += (s1[i]!=s2[i]);
            if(s1[i]!=s2[i] && j1==-1){
                j1=i;
            }
            else if(s1[i]!=s2[i] && j2==-1){
                j2=i;
            }
        }
        if(cn>2 || cn==1)
            return false;

        if(cn==0) return true;

        if(s1[j1]==s2[j2] && s1[j2]==s2[j1])
            return true;

        return false;    
    }
};