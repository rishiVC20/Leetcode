class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        int n=s.size();
        char c1='#',c2='#';
        for(int i=0; i<n; i++){
            if(s[i]!='9'){
                c1=s[i];
                break;
            }
        }
        if(c1=='#'){
            c1='9';
        }
        for(int i=0; i<n; i++){
            if(s[i]!='0'){
                c2=s[i];
                break;
            }
        }
        if(c2=='#'){
            c2='0';
        }
        string s1=s;
        for(int i=0; i<n; i++){
            if(s[i]==c1){
                s[i]='9';
            }
            if(s1[i]==c2){
                s1[i]='0';
            }
        }
        int n1=stoi(s),n2=stoi(s1);
        // cout<<c1<<' '<<c2<<' '<<n1<<' '<<n2;
        return abs(n1-n2);
    }
};