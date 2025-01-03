class Solution {
    #define ll long long
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<ll>pre;
        pre.push_back((ll)nums[0]);

        for(ll i=1; i<nums.size(); i++){
            pre.push_back(pre.back()+(ll)nums[i]);
        }

        ll cn=0;
        for(ll i=0; i<nums.size()-1; i++){
            ll f1=pre.back()-pre[i];
            ll f2=pre[i];

            cn += (f2>=f1);
        }

        return (int)cn;
    }
};