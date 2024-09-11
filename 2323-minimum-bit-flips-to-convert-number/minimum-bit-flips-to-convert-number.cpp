class Solution {
public:
    int minBitFlips(int start, int goal) {
        string a="";
        string b="";
        while(start != 0){
            char k=(start%2)+'0';
            a = k+a;
            start /= 2;
        }
        while(goal != 0){
            char k=(goal%2)+'0';
            b = k+b;
            goal /= 2;
        }
        int p=a.size(),q=b.size();
        while(p<q){
            a = '0'+a;
            p=a.size();
        }
        while(p>q){
            b = '0'+b;
            q=b.size();
        }
        int cn=0;
        for(int i=0; i<p; i++){
            if(a[i]!=b[i])
                cn++;
        }
        // cout<<a<<' '<<b ;
        return cn;
    }
};