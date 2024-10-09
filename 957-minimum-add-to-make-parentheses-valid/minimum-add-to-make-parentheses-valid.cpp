class Solution {
public:
    int minAddToMakeValid(string s) {
        int p=0;
        int q=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                p++;
            }
            else{
                if(p>0)
                    p--;
                else
                    q++;    
            }
        }

        return p+q; 
    }
};