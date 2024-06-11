class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        for (auto i:arr1){
            mp[i]++;
        }

        vector<int>arr;
        for (int i=0; i<arr2.size(); i++){
            int ck = arr2[i];
            while(mp[arr2[i]]){
                arr.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        vector<int>a;
        for (auto i:mp){
            while(i.second){
                a.push_back(i.first);
                i.second--;
            }
        }
        sort(a.begin(),a.end());
        for (auto i:a)
            arr.push_back(i);
        return arr;
    }
};