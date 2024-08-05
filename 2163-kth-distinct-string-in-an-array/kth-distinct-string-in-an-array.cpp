class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        vector<string>v;
        set<string>st;
        int n = arr.size();
        for (int i=0; i<n; i++){
            mp[arr[i]]++;
            
            if (st.find(arr[i]) == st.end()){
                v.push_back(arr[i]);
                st.insert(arr[i]);
            }

        }
        // for (auto i:mp){
        //     cout<<i.first<<' '<<i.second<<' ';
        // }
        string s="";
        int p=0;
        for (auto i:v){
            if (mp.find(i) != mp.end()){
                if (mp[i] == 1){
                    p++;
                    if (p==k){
                        s=i;
                        break;
                    }
                }
            }
        }

        return s;
    }
};