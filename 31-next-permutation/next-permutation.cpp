class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(next_permutation(nums.begin(),nums.end())){
            for(auto i:nums){
                cout<<i<<' ';
            } 
        }
        else{
            sort(nums.begin(),nums.end());
        }
    }
};