class Solution {
    #define ll long long
public:
    vector<int> permute(int n, long long k) {
        ll c1=n/2;
        ll c2=(n+1)/2;
        vector<ll>fac(15);
        fac[0]=fac[1]=1;
        for(ll i=2; i<13; i++){
            fac[i]=i*fac[i-1];
        }
        vector<int>ans;
        map<int,bool>mp;
        if(n>22){
            for(ll i=1; i<n-22; i++){
                ans.push_back(i);
                mp[i]=true;
                if(i%2)
                    c2--;
                else
                    c1--;    
            }
        }
        bool f=false;
        while((int)ans.size()<n && k>0){
            bool t=false;
            if(ans.empty() && n%2==0){
                for(int i=1; i<=n; i++){
                    if(mp.find(i)==mp.end()){
                        ll x1=c1-(i%2==0);
                        ll x2=c2-(i%2);
                        // if (x1 < 0 || x1 >=(ll)fac.size() || x2 < 0 || x2 >= (ll)fac.size()) {
                        //     return {};
                        // }
                        ll tot=fac[x1]*fac[x2];
                        if(k==1 || tot>=k){
                            if(k==1)
                                f=true;
                            c1=x1,c2=x2;
                            ans.push_back(i);
                            t=true;
                            mp[i]=true;
                            break;
                        }
                        else{
                            k-=tot;
                        }
                    }
                }
                if(!t){
                    cout<<"hi";
                    return {};
                }
            }
            else if((ans.empty() && (n&1)) || ans.back()%2==0){
                for(ll i=1; i<=n; i+=2){
                    if(mp.find(i)==mp.end()){
                        ll x1=c1;
                        ll x2=c2-1;
                        // if (x1 < 0 || x1 >=(ll)fac.size() || x2 < 0 || x2 >= (ll)fac.size()) {
                        //     return {};
                        // }
                        ll tot=fac[x1]*fac[x2];
                        if(k==1 || tot>=k){
                            if(k==1)
                                f=true;
                            c1=x1,c2=x2;
                            ans.push_back(i);
                            t=true;
                            mp[i]=true;
                            break;
                        }
                        else{
                            k-=tot;
                        }
                    }
                }
                if(!t){
                    cout<<"hi";
                    return {};
                }
            }
            else{
                for(ll i=2; i<=n; i+=2){
                    if(mp.find(i)==mp.end()){
                        ll x1=c1-1;
                        ll x2=c2;
                        // if (x1 < 0 || x1 >=(ll)fac.size() || x2 < 0 || x2 >= (ll)fac.size()) {
                        //     return {};
                        // }
                        ll tot=fac[x1]*fac[x2];
                        if(k==1 || tot>=k){
                            if(k==1)
                                f=true;
                            c1=x1,c2=x2;
                            ans.push_back(i);
                            t=true;
                            mp[i]=true;
                            break;
                        }
                        else{
                            k-=tot;
                        }
                    }
                }
                if(!t){
                    cout<<"hi";
                    return {};
                }
            }
        }

        // cout<<k<<' '<<f;
        if(k>0 && !f)   
            return {};
        return ans;
    }
};