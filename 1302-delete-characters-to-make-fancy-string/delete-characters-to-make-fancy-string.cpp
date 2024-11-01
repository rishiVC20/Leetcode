class Solution {
public:
    string makeFancyString(string s) {
        string p="";
        p+=s[0];
        int n=s.size();
        int m=1;
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                m++;
            }
            else{
                m=1;
            }
            if(m>2)
                continue;
            p += s[i];    
        }

        return p;
    }
};