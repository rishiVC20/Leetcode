class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Dutch national Flag Algorithm
        //3 pointer algorithm

        int n=nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;

        while (mid <= high){
            if (nums[mid] == 0){
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
            else if (nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }     
        }
    }
};