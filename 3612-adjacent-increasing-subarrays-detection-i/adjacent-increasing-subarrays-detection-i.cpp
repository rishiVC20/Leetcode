class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        vector<vector<int>>v;
        int n=nums.size();
        int cur=0,temp=0;
        if(k==1 && n>1)
            return true;
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                temp++;
            }
            else{
                if(cur==temp){
                    cur=i,temp=i;
                    continue;
                }
                int cp=temp-cur+1;
                vector<int>p;
                p.push_back(cur);
                p.push_back(temp);
                p.push_back(cp);
                v.push_back(p);
                cur=i,temp=i;
            }
        }
        if(cur != temp){
            int cp=temp-cur+1;
            vector<int>p;
            p.push_back(cur);
            p.push_back(temp);
            p.push_back(cp);
            v.push_back(p);
            
        }
        if(v.size() == 0)
            return false;
        int cn=(v[0][2])/2;
        if(cn >= k)
            return true;
        for(auto i:v){
            for(auto j:i)
                cout<<j<<' ';
            cout<<endl;    
        }    
        for(int i=1; i<v.size(); i++){
            int g;
            if(v[i][0] - v[i-1][1] == 1){
                g=min(v[i-1][2],v[i][2]);
                if(g>=k)
                    return true;
            }
            if(v[i][2]/2 >= k)
                return true;
        }    

        return false; 
    }
};