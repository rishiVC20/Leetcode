class Solution {
public:
    
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n+1);
        pre[0]=0;
        for(int i=1; i<=n; i++){
            pre[i]=pre[i-1]+nums[i-1];
        }

        vector<int>a;
        for(int i=k; i<=n; i++){
            int m=pre[i]-pre[i-k];
            a.push_back(m);
        }

        for(auto i:a)
            cout<<i<<' ';

        vector<int>ans(3);

        vector<int>left;

        int j=0;
        int m=a.size();
        for(int i=0; i<m-k; i++){
            if(a[i] > a[j]){
                j=i;
            }
            left.push_back(j);
        }

        vector<int>right(m,0);
        j=m-1;
        for(int i=m-1; i>=k; i--){
            if(a[i] >= a[j]){
                j=i;
            }
            right[i]=j;
        }
        // for(auto i)
        // reverse(right.begin(),right.end());
        int sum=0;
        // cout<<m<<' ';
        for(int mid=k; mid<=m-k-1; mid++){
            int val=a[mid]+a[left[mid-k]]+a[right[mid+k]];
            cout<<'j';
            if(val > sum){
                ans={left[mid-k],mid,right[mid+k]};
                sum=val;
            }
        }

        return ans;


    }
};