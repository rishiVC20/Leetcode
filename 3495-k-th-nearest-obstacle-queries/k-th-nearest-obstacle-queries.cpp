class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        vector<int>ans;
        vector<int>v;
        priority_queue<int>pq;
        for(int i=0; i<queries.size(); i++){
            int p=queries[i][0];
            int q=queries[i][1];
            int dis=abs(p)+abs(q);
            if(pq.size()==k){
                if(dis<pq.top()){
                    pq.pop();
                    pq.push(dis);
                }
            }
            else{
                pq.push(dis);
            }
            if(pq.size()<k){
                ans.push_back(-1);
            }
            else{
                ans.push_back(pq.top());
            }


        }

        return ans;
    }
};