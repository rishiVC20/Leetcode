class Solution {
public:
    pair<bool,int> substr(string a, string b, int j){
        for(int i=j; i<a.size(); i++){
            if(a[i]==b[0]){
                if(i+b.size()-1 >= a.size())
                    return {false,-1};
                string m=a.substr(i,b.size());
                if(m==b)
                    return {true,i+b.size()-1};    
            }
        }

        return {false,-1};
    }
    bool hasMatch(string s, string p) {
        string s1,s2;
        for(int i=0; i<p.size(); i++){
            if(p[i]=='*'){
                if(i>0){
                    s1=p.substr(0,i);
                }
                if(i<p.size()-1){
                    s2=p.substr(i+1);
                }
                break;
            }
        }
        if(s1.size()==0 && s2.size()==0)
            return true;
        // cout<<s1<<' '<<s2<<endl;

        pair<bool,int> t1=substr(s,s1,0);
        // cout<<t1.first<<' '<<t1.second<<' ';
        if(!t1.first && s1.size()>0)
            return false;
        if(s2.size()==0)
            return true;    
        pair<bool,int>t2=substr(s,s2,t1.second+1);

        return t2.first;    
    }
};