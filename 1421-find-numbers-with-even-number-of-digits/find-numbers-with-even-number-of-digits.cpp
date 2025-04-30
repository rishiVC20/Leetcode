class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cn=0;
        for(auto i:nums){
            cn+=(to_string(i).size()%2==0);
        }

        return cn;
    }
};