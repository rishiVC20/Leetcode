class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int>mp;
        for(int i=1; i<=n; i++){
            int p=i;
            int cn=0;
            while(p!=0){
                cn+=p%10;
                p/=10;
            }
            mp[cn]++;
        }
        int k=0;
        int rp=0;
        for(auto i:mp){
            if(i.second>=k){
                k=i.second;
            }
        }
        for(auto i:mp){
            if(k==i.second){
                rp++;
            }
        }
        // cout<<k<<' ';
        return rp;
    }
};