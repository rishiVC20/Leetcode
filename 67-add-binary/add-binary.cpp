class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size();
        int m=b.size();
        while(n<m){
            a='0'+a;
            n=a.size();
        }
        while(m<n){
            b='0'+b;
            m=b.size();
        }
        int k=a.size();
        string p="";
        bool f=false;
        for(int i=k-1; i>=0; i--){
            if(a[i]=='0' && b[i]=='0'){
                char m;
                if(!f)
                    m='0';
                else
                    m='1';
                f=false;    
                p=m+p;    
            }
            else if((a[i]=='0' && b[i]=='1') || (a[i]=='1' && b[i]=='0')){
                char m;
                if(!f){
                    m='1';
                    f=false;
                }
                else{
                    m='0';
                    f=true;
                }
                // f=false;
                p=m+p;
            }
            else{
                char m;
                if(f){
                    m='1';
                }
                else{
                    m='0';
                }
                f=true;
                p=m+p;
            }
        }
        cout<<f<<' ';
        if(f)
            p='1'+p;

        return p;
    }
};