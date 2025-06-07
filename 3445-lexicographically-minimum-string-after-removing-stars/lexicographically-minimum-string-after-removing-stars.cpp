class Solution {
public:
    struct Compare {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first)
                return a.second < b.second; // larger second comes first
            return a.first > b.first; // smaller first comes first
        }
    };

    string clearStars(string s) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        int n=s.size();
        map<int,int>mp;
        for(int i=0; i<n; i++){
            if(s[i]=='*'){
                pair<int,int> qtop=pq.top();
                pq.pop();
                mp[qtop.second]++;
            }
            else{
                pq.push({s[i]-'a',i});
            }
        }

        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]!='*' && mp.find(i)==mp.end()){
                ans.push_back(s[i]);
            }
            
        }

        return ans;

    }
};