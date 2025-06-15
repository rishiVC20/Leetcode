class Solution {
    #define ll long long
public:
    long long maximumProduct(vector<int>& nums, int m) {
        ll n=nums.size();
        vector<ll>neg(n,LLONG_MAX);
        vector<ll>pos(n,LLONG_MIN);
        vector<ll>pn(n,LLONG_MAX);
        vector<ll>mini(n,LLONG_MAX);
        vector<ll>maxi(n,LLONG_MIN);
        mini[n-1]=nums[n-1],maxi[n-1]=nums[n-1];
        for(int i=n-1; i>=0; i--){
            if(i==n-1){
                if(nums[i]<0){
                    neg[i]=(ll)nums[i];
                    pn[i]=(ll)nums[i];
                }
                else{
                    pos[i]=(ll)nums[i];
                }
            }
            else{
                if(nums[i]<0){
                    neg[i]=min((ll)nums[i],neg[i+1]);
                    pn[i]=max((ll)nums[i],pn[i+1]);
                    pos[i]=pos[i+1];
                }
                else{
                    pos[i]=max((ll)nums[i],pos[i+1]);
                    pn[i]=pn[i+1];
                    neg[i]=neg[i+1];
                }
            }
            if(i!=n-1){
                mini[i]=min((ll)nums[i],mini[i+1]);
                maxi[i]=max((ll)nums[i],maxi[i+1]);
            }
        }

        ll ans=LLONG_MIN;

        // for(int i=0; i<n; i++){
        //     cout<<neg[i]<<' ';
        // }
        // cout<<endl;
        // for(int i=0; i<n; i++){
        //     cout<<pos[i]<<' ';
        // }
        for(ll i=0; i<n-m+1; i++){
            // cout<<"hi ";
            // cout<<nums[i]<<' '<<neg[i+m-1]<<' '<<pos[i+m-1]<<' '<<pn[i]<<endl;
            if(neg[i+m-1]!=LLONG_MAX){
                ans=max(ans,(ll)(nums[i]*neg[i+m-1]));
            }
            if(pos[i+m-1]!=LLONG_MIN){
                ans=max(ans,(ll)(nums[i]*pos[i+m-1]));
            }
            if(pn[i+m-1]!=LLONG_MAX){
                ans=max(ans,(ll)(nums[i]*pn[i+m-1]));
            }
            ans=max(ans,(ll)(nums[i]*mini[i+m-1]));
            ans=max(ans,(ll)(nums[i]*maxi[i+m-1]));
        }

        return ans;
    }
};