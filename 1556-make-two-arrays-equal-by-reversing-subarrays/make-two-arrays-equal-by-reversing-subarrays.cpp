class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int>mp;
        for (auto i:target){
            mp[i]++;
        }
        for (auto i:arr){
            if (mp[i] > 0){
                mp[i]--;
            }
            else{
                return false;
            }
        }

        return true;
    }
};