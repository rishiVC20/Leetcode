class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
        }

        for(auto i:arr){
            mp[i]--;
            if(mp.find(2*i) != mp.end() && mp[2*i]>0)
                return true;
            mp[i]++;
        }


        return false;            
    }
};