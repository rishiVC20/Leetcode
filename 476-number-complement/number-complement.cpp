class Solution {
public:
    int findComplement(int num) {
        long long k=num;
        long long ans=0;
        string s="";
        while(k){
            long long d=k&1;
            if(d==1){
                s='0'+s;
            }
            else{
                s='1'+s;
            }
            k>>=1;
        }
        cout<<s<<' ';
        long long n=s.size();
        long long b=0;
        for(int i=n-1; i>=0; i--){
            long long j=s[i]-'0';
            ans += j*pow(2,b);
            b++;
        }

        return (int)ans;

    }
};