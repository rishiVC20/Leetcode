class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for (int i=1; i<nums.size(); i++){
            if (nums[i] <= nums[i-1]){
                sum += nums[i-1]-nums[i] + 1;
                nums[i] = nums[i-1] + 1;
            }
        }

        return sum;
    }
};