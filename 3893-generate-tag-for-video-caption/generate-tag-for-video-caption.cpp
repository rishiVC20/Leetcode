class Solution {
public:
    string generateTag(string caption) {
        int n=caption.size();
        string ans="";
        ans+='#';
        bool f=true;
        int ze=-1,zo=-1;
        for(int i=0; i<n; i++){
            if(caption[i]!=' '){
                f=false;
                ze=caption[i]-'a';
                zo=caption[i]-'A';
                break;
            }
        }
        if(f){
            return "#";
        }
        // cout<<ze<<' '<<zo;
        if(ze>=0 && ze<=25){
            ans+='a'+ze;
        }
        else{
            ans+=('a'+zo);
        }
        int cn=1;
        int st;
        bool kr=true;
        for(int i=0; i<n; i++){
            if(caption[i]!=' ' && kr==true){
                kr=false;
            }
            else if(caption[i]!=' ' && kr==false){
                st=i;
                break;
            }
        }
        for(int i=st; i<caption.size(); i++){
            if(caption[i]==' '){
                cn=0;
                continue;
            }
            cn++;
            // cout<<cn<<' ';
            if(cn>=100){
                continue;
            }
            int k1=caption[i]-'a';
            int k2=caption[i]-'A';

            if(k1>=0 && k1<=25){
                if (caption[i-1]==' '){
                    ans+='A'+k1;
                }
                else{
                    ans+=caption[i];
                }
            }
            else{
                if(caption[i-1]==' '){
                    ans+=caption[i];
                }
                else{
                    ans+='a'+k2;
                }
            }
        }

        while(ans.size()>100){
            ans.pop_back();
        }

        return ans;
    }
};