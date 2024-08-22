class Solution {
public:
    int findComplement(int num) {
        int k=num;
        int ans=0;
        string s="";
        while(k){
            int d=k&1;
            if(d==1){
                s='0'+s;
            }
            else{
                s='1'+s;
            }
            k>>=1;
        }
        cout<<s<<' ';
        int n=s.size();
        int b=0;
        for(int i=n-1; i>=0; i--){
            int j=s[i]-'0';
            ans += j*pow(2,b);
            b++;
        }

        return ans;

    }
};