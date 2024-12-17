class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int>v(26,0);
        for(int i=0; i<s.size(); i++){
            int ch=s[i]-'a';
            v[ch]++;
        }
        // for(auto i:v)
        //     cout<<i<<" ";
        // cout<<endl;    
        string ans="";
        bool gh=false;
        while(ans.size() < s.size()){
            bool f=true;
            for(int i=25; i>=0; i--){
                if(v[i]>0){
                    
                    if(f){
                        // if(ans.back()==i+'a'){ 
                        //     gh=true;
                        //     break;
                        // }
                        int ch=v[i];
                        char cp=i+'a';
                        if(ch>repeatLimit){
                            
                            ch=repeatLimit;
                            string g(ch,i+'a');
                            ans+=g;
                            v[i]-=repeatLimit;
                            f=false;
                        }
                        else{
                            string g(ch,i+'a');
                            ans+=g;
                            v[i]=0;
                            f=true;
                        }
                    }
                    else{
                        char cp=i+'a';
                        ans+=cp;
                        v[i]--;
                        break;
                    }
                }
                
            }
            // if(gh==true)
            //         break;
        }

        int m=ans.size();
        // cout<<ans;
        string res="";
        int curr=1;
        res+=ans[0];
        for(int i=1; i<m; i++){
            if(ans[i]==ans[i-1]){
                curr++;
            }
            else{
                curr=1;
            }
            if(curr>repeatLimit) continue;

            res+=ans[i];
        }

        return res;
    }
};