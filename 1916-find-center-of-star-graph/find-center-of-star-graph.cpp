class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mp;
        int n = edges.size();
        for (auto i:edges)
        {
            int u = i[0];
            int v = i[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        for (auto i:mp)
        {
            int m = i.second.size();
            if (m==n)
                return i.first;
        }

        return -1;
    }
};