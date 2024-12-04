class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();

        // if(m<n)
        //     return false;

        int i=0,j=0;

        for(i=0; j<m && i<n; i++){
            char c=str2[j];
            if(str1[i]==c){
                j++;
                continue;
            }
            int p=c-'a';
            p--;
            char d;
            if(p<0){
                d='z';
            }
            else{
                d='a'+p;
            }
            if(str1[i]==d){
                j++;
            }
            // cout<<p<<' ';
        }    
        // cout<<i<<" "<<j;
        if(j==m)
            return true;


        return false;   
    }
};