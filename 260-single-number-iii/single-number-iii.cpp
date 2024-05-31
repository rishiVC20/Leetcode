class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for (auto i:nums)
        {
            mp[i]++;
        }
        vector<int>p;
        for (auto i:mp)
        {
            if (i.second==1){
                p.push_back(i.first);
            }
        }

        return p;
    }
};