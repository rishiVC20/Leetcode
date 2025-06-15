class Solution {
    const int mod=1e9+7;
    #define ll long long
public:
    int specialTriplets(vector<int>& nums) {
        map<ll,ll>m1,m2;
        m1[nums[0]]++;
        for(int i=1; i<nums.size(); i++){
            m2[nums[i]]++;
        }

        ll cn=0;
        for(int i=1; i<nums.size()-1; i++){
            m2[nums[i]]--;
            if(m1.find(nums[i]*2)!=m1.end() && m2.find(nums[i]*2)!=m2.end()){
                cn=(cn+(m1[nums[i]*2]*m2[nums[i]*2])%mod)%mod;
            }
            m1[nums[i]]++;
        }

        return (int)cn;
    }
};