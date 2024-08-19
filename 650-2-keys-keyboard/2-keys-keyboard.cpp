class Solution {
public:
    int checkPrime(int x){
        for(int i=x/2; i>=2; i--){
            if(x%i==0){
                return i;
            }
        }
        return -1;
    }
    vector<int>pre;
    void solve(){
        pre.resize(1701);  
        pre.push_back(1);
        for(int i=2; i<=1700; i++){
            int pp=checkPrime(i);
            // cout<<pp<<' ';
            if(pp != -1){
                int k = i/pp;
                pre[i]=pre[pp]+k;
            }
            else{
                pre[i]=i;
            }
        }
        // for(int i=1; i<=10 ;i++){
        //     cout<<pre[i]<<' ';
        // }
    }
    
    int minSteps(int n) {
        if(n==1 )
            return 0;
        solve();
        

        return pre[n];
    }
};