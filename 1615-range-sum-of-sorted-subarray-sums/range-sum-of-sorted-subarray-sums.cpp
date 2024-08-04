class Solution {
public:
    const int MOD = 1000000007;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>a;
        // int n = nums.size();
        for (int i=0; i<n; i++){
            int sum = 0;
            for (int j=i; j<n; j++){
                sum += nums[j];
                a.push_back(sum);
            }
            
        }
        sort(a.begin(),a.end());
        
        vector<int>pre(a.size()+1);
        pre[0]=0;
        pre[1]=(a[0])%MOD;
        for (int i=1; i<a.size(); i++){
            pre[i+1]=(pre[i]+a[i])%MOD;
        }    
        // for (auto i:pre)
        //     cout<<i<<' ';
        return pre[right]-pre[left-1];

        // return 1;
    }
};