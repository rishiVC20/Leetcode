class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        int ln=0;
        int wrd=0;
        vector<pair<int,int>>t(n);
         
        for(int i=0; i<n; ){
            int m=words[i].size();
            if(wrd+m <= maxWidth){
                wrd+=m;
            }
            else{
                ln++;
                wrd=0;
                continue;
            }
            if(wrd+1 <= maxWidth){
                wrd++;
            }
            t[i]={ln,i};
            if(wrd==maxWidth){
                ln++;
                wrd=0;
            }
            
            i++;

        }
        map<int,int>mp;
        map<int,int>m2;
        int tp=0;
        for(int i=0; i<n; i++){
            m2[t[i].first]+=words[i].size();
        }
        for(auto i:t){
            mp[i.first]++;
            tp=max(tp,i.first);
            // cout<<i<<' ';
        }
        vector<string>s;
        int b=0;
        for(int i=0; i<=tp; i++){
            if(i==tp){
                string dp="";
                int g=mp[i];
                for(int j=0; j<g; j++){
                    dp+=words[b];
                    b++;
                    if((int)dp.size()<maxWidth)
                        dp+=" ";
                } 
                int q=dp.size();
                // cout<<q<<' ';
                for(int j=q; j<maxWidth; j++){
                    dp+=" ";
                }
                s.push_back(dp);
                break;
            }
            int g=m2[i];
            // cout<<g<<' ';
            int tr=maxWidth-g;
            int r=mp[i]-1;
            int d;
            if(r!=0){
                d=tr/r;
            }
            string dp="";
            for(int j=0; j<mp[i]; j++){
                if(j==mp[i]-1){
                    // cout<<words[b]<<' ';
                    dp+=words[b];
                    b++;
                    int q=dp.size();
                    for(int w=q; w<maxWidth; w++){
                        dp+=" ";
                    }
                    break;
                }
                dp+=words[b];
                b++;
                for(int k=0; k<d; k++){
                    dp+=" ";
                }
                if(tr%r > j){
                    // cout<<"hi ";
                    dp+=" ";
                }
            }
            s.push_back(dp);
        }
        return s;
    }
};