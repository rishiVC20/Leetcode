class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        vector<bool>f(n,true);
        int j=-1;
        for(int i=0; i<n; i++){
            if(s[i]>='0' && s[i]<='9'){
                f[i]=false;
                for(int j=i-1; j>=0; j--){
                    if(s[j]>='a' && s[j]<='z' && f[j]==true){
                        f[j]=false;
                        break;
                    }
                }
            }
        }

        string p="";
        for(int i=0; i<n; i++){
            if(f[i]==true){
                p.push_back(s[i]);
            }
        }

        return p;
    }
};