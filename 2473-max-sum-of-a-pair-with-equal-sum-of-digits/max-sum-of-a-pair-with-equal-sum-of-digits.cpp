class Solution {
public:
    int sum(int j){
        int cn=0;
        while(j!=0){
            cn+=j%10;
            j/=10;
        }
        return cn;
    }
    int maximumSum(vector<int>& nums) {
        map<int,priority_queue<int>>pq;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int t=sum(nums[i]);
            pq[t].push(nums[i]);
        }

        int maxi=-1;
        for(auto i:pq){
            if(i.second.size()<2){
                continue;
            }
            priority_queue<int>q=i.second;
            int fir=q.top();
            q.pop();
            int sec=q.top();
            q.pop();
            maxi=max(maxi,fir+sec);
        }

        return maxi;
    }
};