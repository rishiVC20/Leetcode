class Solution {
public:
    int getLucky(string s, int k) {
        vector<int>ans;
        for(int i=0; i<s.size(); i++){
            int lm=(s[i]-'a')+1;
            // cout<<lm<<"k ";
            string nn=to_string(lm);
            int lp=0;
            while(lp<nn.size()){
                ans.push_back(nn[lp]-'0');
                lp++;
            }
            
        }
        // for(auto i:ans)
        //     cout<<i<<' ';
        while(k>0 ){
            int sum=0;
            for(int i=0; i<ans.size(); i++){
                sum += ans[i];
            }
            ans.clear();
            string h=to_string(sum);
            while(sum>0){
                ans.push_back(sum%10);
                sum/=10;
            }
            reverse(ans.begin(),ans.end());
            // for(auto i:ans)
            //     cout<<i<<' ';
            
            k--;
        }
        string jj="";
        for(auto i:ans)
            jj += i+'0';  
        // cout<<jj<<' ';    
        int num=stoi(jj);

        return num;    
    }
};