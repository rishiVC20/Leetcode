// class Solution {
// public:
//     int minimumSize(vector<int>& nums, int maxOperations) {
        // int n=nums.size();

        // priority_queue<int>pq;
        // int k=0;
        // for(auto i:nums){
        //     pq.push(i);
        // }
        // while(k<maxOperations && pq.top()>1){
        //     int p=pq.top();
        //     pq.pop();
        //     int m=p/2;
        //     int t=p-m;
        //     pq.push(m),pq.push(t);
        //     k++;
        // }

        // return pq.top();

        class Solution {
public:

    bool check(int mid, vector<int> &nums, int maxOperations) {
        int n = nums.size(); 
        for (auto &num: nums) {
            maxOperations -= (num + mid - 1) / mid - 1;
        }
        return maxOperations >= 0; 
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size(); 
        int l = 1, r = 1e9; 
        int ans = 1e9; 
        while (l <= r) {
            int mid = l + (r - l) / 2; 
            if (check(mid, nums, maxOperations)) {
                ans = mid; 
                r = mid - 1; 
            } else {
                l = mid + 1; 
            }
        }
        return ans; 
    }
};
//     }
// };