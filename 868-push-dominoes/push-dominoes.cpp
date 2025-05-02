class Solution {
public:
    string pushDominoes(string dominoes) {
        string s1=dominoes,s2=dominoes;

        bool f=false;
        int n=dominoes.size();
        for(int i=0; i<n; i++){
            if(s1[i]=='R'){
                f=true;
            }
            else if(s1[i]=='L'){
                f=false;
            }
            else if(f==true){
                s1[i]='R';
            }
        }
        f=false;;
        for(int i=n-1; i>=0; i--){
            if(s2[i]=='L'){
                f=true;
            }
            else if(s2[i]=='R'){
                f=false;
            }
            else if(f){
                s2[i]='L';
            }
        }

        vector<int>dr;
        int cn=0;
        for(int i=0; i<n; i++){
            if(s1[i]=='R' && s2[i]=='L'){
                cn++;
            }
            else if(cn>0){
                dr.push_back(cn);
                cn=0;
            }
        }
        string ans=dominoes;
        for(int i=0; i<n; i++){
            if(s1[i]=='R' && s2[i]=='.'){
                ans[i]='R';
            }
            if(s1[i]=='.' && s2[i]=='L'){
                ans[i]='L';
            }
        }
        int i=0;
        int j=0;
        while(i<n && j<dr.size()){
            if(s1[i]=='R' && s2[i]=='L'){
                int p=dr[j];
                int f=p/2;
                for(int k=0; k<f; k++){
                    ans[i]='R';
                    i++;
                }
                if(p&1){
                    i++;
                }
                for(int k=0; k<f; k++){
                    ans[i]='L';
                    i++;
                }
                j++;
            }
            else{
                i++;
            }
        }

        return ans;

    }
};