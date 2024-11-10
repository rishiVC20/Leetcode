class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>v;
        int cur=0;
        int temp=0;
        
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                temp++;
            }
            else{
                if(temp==cur){
                    temp=i,cur=i;
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
            return 1;
        // for(auto i:v){
        //     for(auto j:i)
        //         cout<<j<<' ';
        //     cout<<endl;    
        // }    
        int cn=(v[0][2])/2;
        for(int i=1; i<v.size(); i++){
            int k;
            if(v[i][0]-v[i-1][1] == 1){
                k=min(v[i-1][2],v[i][2]);
                cn=max(cn,k);
                
            }
            int h=v[i][2]/2;
                cn=max(cn,h);
        }

        return cn;
    }
};