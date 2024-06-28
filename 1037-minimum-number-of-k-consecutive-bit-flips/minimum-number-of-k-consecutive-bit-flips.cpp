class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>count(n,0);

        int sum = 0;
        int cn = 0;
        if (nums[0]==0){
            count[k-1] = 1;
            sum++;
            cn = 1;
        }

        for (int i=1; i<(n-k)+1; i++){
            cn -= count[i-1];
            cn += count[i+(k-1)];

            int x = cn%2;
            if (nums[i]==0 && x==0){
                sum++;
                cn++;
                count[i+(k-1)] = 1;
            }
            if (nums[i]==1 && x==1){
                sum++;
                cn++;
                count[i+(k-1)] = 1;
            }

            cout<<sum<<' ';
        }

        for (int i=(n-k)+1; i<n; i++){
            if (cn==0 && nums[i]==0)
                return -1;
            cn -= count[i-1];
            int x = cn%2;
            if (nums[i]==0 && x==0) 
                return -1;
            if (nums[i]==1 && x==1)
                return -1;    
        }

        return sum;
    }
};