class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i=0, j=1, k=2;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if (n == 1)
            return  nums[0];
        for (int p=0; p<nums.size()-2; p++)
        {
            if (nums[i]==nums[j] && nums[j]==nums[k]){
                i+=3, j+=3, k+=3;
                if (k > nums.size())
                    return nums[nums.size()-1];
                continue;
            }
            else 
                return nums[i]^nums[j]^nums[k];    
        }

        return -1;
    }
};