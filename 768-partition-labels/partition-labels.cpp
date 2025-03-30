class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>a(26,0);
        int n=s.size();
        for(int i=0; i<s.size(); i++){
            int p=s[i]-'a';
            a[p]=i;
        }

        set<char>sp;
        vector<int>ans;
        // ans.push_back(0);
        for(int i=0; i<n; i++){
            int t=s[i]-'a';
            if(a[t]==i){
                if(sp.find(s[i])!=sp.end()){
                    sp.erase(s[i]);
                }
                if(sp.size()==0){
                    ans.push_back(i);
                }
            }
            else{
                sp.insert(s[i]);
            }
        }

        if(ans.size()==1){
            return {ans[0]+1};
        }
        vector<int>dp;
        dp.push_back(ans[0]+1);
        for(int i=1; i<(int)ans.size(); i++){
            int k=ans[i]-ans[i-1];
            dp.push_back(k);
        }

        return dp;
    }
};