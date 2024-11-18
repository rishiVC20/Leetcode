class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        for(int i=0; i<n; i++){
            code.push_back(code[i]);
        }
        vector<int>ans;
        if(k==0){
            for(int i=0; i<n; i++)
                ans.push_back(0);
            return ans;    
        }
        if(k>0){
            int j=1;
            int sum=0;
            int x=1,m=1;
            while(j<=k){
                sum += code[x++];
                j++;
            }
            cout<<x<<' ';
            ans.push_back(sum);
            while(ans.size() < n){
                sum -= code[m++];
                sum += code[x++];
                ans.push_back(sum);
            }
            return ans;

        }
        else{
            k=abs(k);
            int b=code.size();
            int j=1;
            int x=b-2,m=b-2;
            int sum=0;
            while(j<=k){
                sum += code[x--];
                j++;
            }
            ans.push_back(sum);
            while(ans.size() < n){
                // cout<<m<<' '<<x<<' ';
                sum -= code[m--];
                sum += code[x--];
                
                ans.push_back(sum);
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }

        return ans;
    }
};