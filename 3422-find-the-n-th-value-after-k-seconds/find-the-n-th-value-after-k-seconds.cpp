class Solution {
public:
    int mod = 1e9+7;
    int valueAfterKSeconds(int n, int k) {
        vector<int>a(n,1);
        vector<int>pre(n);
        pre[0] = 1;
        for (int i=1; i<n; i++)
        {
            (pre[i]) = (pre[i-1]) + (a[i]);
        }
        if (k==1)
            return pre[n-1]%mod;

        int m = k;
        a = pre;
        for (int i=2; i<=k; i++)
        {
            a = pre;
            for  (int j=1; j<n; j++)
            {
                pre[j] = (pre[j-1] + a[j])%mod;
            }
        }    

        return pre[n-1]%mod;
    }
};