class Solution {
public:
    int maxScore(string s) {
        int t1=0,t2=0;
        for(auto i:s){
            t2 += (i=='1');
        }

        int cn=0;
        for(int i=0; i<s.size()-1; i++){
            if(s[i]=='1'){
                t2--;
            }
            else{
                t1++;
            }
            cn=max(cn,t1+t2);
        }

        return cn;
    }
};