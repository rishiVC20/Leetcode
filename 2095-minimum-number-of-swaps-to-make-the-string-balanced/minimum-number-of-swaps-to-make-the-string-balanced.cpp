class Solution {
public:
    int minSwaps(string s) {
        int p=0;
        int q=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='['){
                p++;
            }
            else {
                if(p>0)
                    p--;
                else
                    q++;    
            }
        }
        // if(q==1)
        //     return 1;
        return (q+1)/2;
    }
};