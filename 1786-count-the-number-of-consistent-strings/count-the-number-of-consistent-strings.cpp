class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cn=0;
        int n=words.size();
        set<char>t;
        for(auto i:allowed)
            t.insert(i);
        // for(auto i:t)
        //     cout<<i<<' ';    
        for(int i=0; i<n; i++){
            string p=words[i];
            set<char>v;
            for(auto j:p){
                v.insert(j);
            }
            // if(v.size()!=allowed.size())
            //     continue;
            bool f=true;    
            for(auto j:v){
                if(t.find(j)==t.end()){
                    f=false;
                    break;
                }
            }    
            if(!f)
                continue;
            cn++;    
        }

        return cn;
    }
};