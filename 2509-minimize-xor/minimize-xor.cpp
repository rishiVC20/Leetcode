class Solution {
    #define onebit(x) __builtin_popcountll(x)
public:
    int binToDec(string s){
        int ans=0;
        reverse(s.begin(),s.end());
        int k=0;
        for(int i=0; i<s.size(); i++){
            int t=pow(2,k);
            int f=s[i]-'0';
            ans += f*t;
            k++;
        }

        return ans;
    }
    string decToBin(int k){
        string p="";
        while(k!=0){
            if(k&1)
                p+='1';
            else
                p+='0';    
            k>>=1;
        }
        reverse(p.begin(),p.end());
        return p;
    }
    int minimizeXor(int num1, int num2) {
        int cn=onebit(num2);
        string t=decToBin(num1);
        cout<<t<<' ';
        string g="";
        int i=0;
        while(cn>0 && i<t.size()){
            if(t[i]=='1'){
                g.push_back('1');
                cn--;
                
            }
            else{
                g.push_back('0');
            }
            i++;
        }
        while(i<t.size()){
            g.push_back('0');
            i++;
        }
        i=g.size()-1;
        while(cn>0 && i>=0){
            if(t[i]=='0'){
                g[i]='1';
                cn--;
            }
            i--;
        }

        while(cn>0){
            g = '1'+g;
            cn--;
        }
        cout<<g<<' ';
        int m=binToDec(g);

        return m;
    }
};