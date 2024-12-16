class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        
        for(int i=0; i<nums.size(); i++){
            q.push(make_pair(nums[i],i));
        }

        for(int i=0; i<k; i++){
            auto it=q.top();
            int a=it.first,b=it.second;
            q.pop();
            a=a*multiplier;
            q.push(make_pair(a,b));
        }

        vector<int>ans(nums.size());

        while(!q.empty()){
            auto it=q.top();
            int a=it.first,b=it.second;
            ans[b]=a;
            q.pop();
        }

        return ans;
    }
};