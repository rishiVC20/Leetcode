class Solution {
public:
    string sp(string s){
        string g="";
        int n=s.size();
        if(n==1){
            return "11";
        }
        int cur=1;
        // cout<<s<<' ';
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                cur++;
            }
            else{
                string d=to_string(cur);
                g+=d;
                g.push_back(s[i-1]);
                cur=1;
            }
            if(i==n-1){
                string d=to_string(cur);
                g+=d;
                g.push_back(s[i]); 
            }
        }
        // cout<<g<<' ';
        return g;
    }
    string countAndSay(int n) {
        string s="1";

        for(int i=1; i<n; i++){
            string p=sp(s);
            cout<<p<<' ';
            s=p;
        }
        return s;
    }
};