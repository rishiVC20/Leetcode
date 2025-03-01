class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0){
            return 0;
        }
        vector<int>v(n);
        v[0]=1;
        map<char,int>mp;
        mp[s[0]]=0;
        
        for(int i=1; i<n; i++){
            char t=s[i];
            if(mp.find(t)!=mp.end()){
                int k=mp[t];
                int sp=i-k;
                v[i]=min(sp,v[i-1]+1);
                mp[t]=i;
            }
            else{
                v[i]=v[i-1]+1;
                mp[t]=i;
            }
        }
        int ans=*max_element(v.begin(),v.end());

        return ans;
    }
};