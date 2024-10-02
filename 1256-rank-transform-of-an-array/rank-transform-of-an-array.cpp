class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mp;
        vector<int>nums=arr;
        sort(nums.begin(),nums.end());
        int k=1;
        for(int i=0; i<arr.size(); i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=k;
                k++;
            }
        }
        nums.clear();
        for(auto i:arr){
            nums.push_back(mp[i]);
        }

        return nums;
    }
};