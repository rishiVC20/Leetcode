class Solution {
public:
    int maxDiff(int num) {
        string s=to_string(num);
        int n=s.size();
        char c1='#',c2='#';

        for(int i=0; i<n; i++){
            if(s[i]!='9'){
                c1=s[i];
                break;
            }
        }
        // cout<<c1<<endl;
        string s1=s;
        for(int i=0; i<n; i++){
            if(s1[i]>'1'){
                c2=s1[i];
                break;
            }
        }
        if(c1=='#'){
            c1='9';
        }
        if(c2=='#'){
            c2='0';
        }
        char km='0';
        for(int i=0; i<n; i++){
            if(s[i]==c1){
                s[i]='9';
            }
            if(s1[i]==c2){
                if(i==0){
                    s1[i]='1';
                    km='1';
                }
                else{
                    s1[i]=km;
                }
            }
        }

        int n1=stoi(s),n2=stoi(s1);
        // cout<<s<<' '<<s1<<' '<<c1<<' '<<c2<<' '<<n1<<' '<<n2;
        return abs(n1-n2);
    }
};