class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n=words1.size();
        vector<vector<int>>v(n,vector<int>(26,0));
        vector<int>a(26,0);
        for(int i=0; i<words2.size(); i++){
            string s=words2[i];
            vector<int>d(26,0);
            for(int j=0; j<s.size(); j++){
                int ch=s[j]-'a';
                d[ch]++;
            }
            for(int j=0; j<26; j++){
                a[j]=max(d[j],a[j]);
            }
            // a=d;
        }

        vector<string>ans;
        for(int i=0; i<n; i++){
            string s=words1[i];
            for(int j=0; j<s.size(); j++){
                int ch=s[j]-'a';
                v[i][ch]++;
            }
            // cout<<s<<' ';
            // for(int j=0; j<26; j++){
            //     char c='a'+j;
            //     cout<<c<<' '<<v[i][j]<<' '<<a[j]<<endl;
            // }
            bool f=true;
            for(int j=0; j<26; j++){
                if(v[i][j] < a[j]){
                    // cout<<i<<' '<<j<<' ';
                    f=false;
                    break;
                }
            }
            if(f)
                ans.push_back(s);
        }

        return ans;


    }
};