class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>v(26,0);
        int n=s.size();
        vector<int>a(n+1,0);

        for(auto i:shifts){
            a[i[0]] += (i[2]==1);
            a[i[1]+1] -= (i[2]==1);

            // a[i[0]] -= (i[2]==0);
            // a[i[1]] -= (i[2]==0);
        }
        for(int i=1; i<=n; i++){
            a[i] += a[i-1];
        }
        // for(int i=0; i<n; i++){
        //     cout<<a[i]<<' ';
        // }
        // cout<<endl;
        string ans="";

        for(int i=0; i<n; i++){
            int p=a[i];
            if(p==0){
                ans.push_back(s[i]);
                continue;
            }
            int cn=(s[i]-'a')+p;

            if(('z'-s[i]) < p){
                p -= ('z'-s[i]);
                p = p%26;
                if(p==0){
                    cout<<"mcccc ";
                }
                if(p==0){
                    ans.push_back('z');
                    continue;
                }
                char ch='a'+(p)-1;
                if(ch<'a' || ch>'z'){
                    cout<<"He ";
                }
                ans.push_back(ch);
                continue;
            }

            char ch=s[i]+p;
            if(ch<'a' || ch>'z'){
                    cout<<"He ";
                }
            ans.push_back(ch);
        }
        // cout<<ans<<' ';
        // for(auto i:ans){
        //     if(i<'a' || i>'z'){
        //         cout<<"He ";
        //     }
        // }
        // cout<<endl;
        vector<int>b(n+1,0);


        for(auto i:shifts){
            b[i[0]] += (i[2]==0);
            b[i[1]+1] -= (i[2]==0);

        }

        for(int i=1; i<=n; i++){
            b[i] += b[i-1];
        }

        string c="";
        for(int i=0; i<n; i++){
            int p=b[i];
            if(p==0){
                c.push_back(ans[i]);
                continue;
            }

            int cn=(ans[i]-'a');

            if(cn < p){
                p -= cn;
                p=p%26;
                char ch='z'-p+1;
                if(p==0){
                    c.push_back('a');
                    continue;
                }
                // if(ch>='a' && ch<='z')
                    c.push_back(ch);
                if( ch>'z'){
                    cout<<"Hi ";
                }    
                continue;
                // int m=(ans[i]-'a');
                // int k=abs(cn);
                // k -= m;
                // k=k%26;
                // char ch='z'-k;
                // c.push_back(ch);
                // continue;
            }

            char ch=ans[i]-p;
            cout<<ch<<' ';
            // if(ch>='a' && ch<='z')
                c.push_back(ch);
            if(ch>'z' ){
                    cout<<"Hi ";
                }    

        }

        return c;
        
    }
};