class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool see ;
        if (nums[0]%2)
            see = 1;
        else
            see = 0;
        for (int i=1; i <nums.size(); i++)
        {
            if (nums[i]%2==0 && see==1)
                see=0;
            else if (nums[i]%2!=0 && see==0)
                see=1;
            else
                return false;         
        }        
        return true;

    }
};