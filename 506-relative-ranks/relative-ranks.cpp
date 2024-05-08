class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int>store=score;
        vector<string>ans={"Gold Medal","Silver Medal","Bronze Medal"};
        sort(store.begin(),store.end(),greater<int>());
        unordered_map<int,string>mp;
        for (int i=0; i<n; i++){
            if (i<3){
                mp[store[i]]=ans[i];
            }
            else{
                mp[store[i]]=to_string(i+1);
            }
        }
        vector<string>c;
        for (auto i:score){
            c.push_back(mp[i]);
        }

        return c;
    }
};