class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if (n<=4){
            return 0;
        }
        // int mini = INT_MAX;
        // for (int i=0; i<=3; i++){
        //     // mini = min(mini,nums[i]-nums[i-1]);
        //     int k=-1;
        //     int l=-1;
        //     mini = INT_MAX;
        //     for (int j=0; j<n-1; j++){
        //         if (mini > nums[j+1]-nums[j]){
        //             mini = nums[j+1]-nums[j];
        //             k = j, l = j+1;
        //         }
        //     }
        //     if (k!=-1 && l != -1){
        //         nums[k] = nums[l];
        //     }
        // }

        // for (auto i:nums)
        //     cout<<i<<' ';
        // for (int i=0; i<n-1; i++){
        //     mini = min(mini,nums[i+1]-nums[i]);
        // }

        int mini = INT_MAX;
        mini = min(mini,nums[n-4]-nums[0]);
        mini = min(mini,nums[n-1]-nums[3]);
        mini = min(mini,nums[n-3]-nums[1]);
        mini = min(mini,nums[n-2]-nums[2]);

        return mini; 
    }
};