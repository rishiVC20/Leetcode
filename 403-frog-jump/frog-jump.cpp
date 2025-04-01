class Solution {
public:
    bool check(set<int> &st, int jp, int prev, int maxi, map<int,int> &mp){ 
        if(st.find(jp)==st.end()){
            return false;
        }
        if(prev<=0){
            return false;
        }
        if(jp>maxi || jp<0){
            return false;
        }
        if(jp==maxi){
            return true;
        }
        // int p=mp[jp];
        long long kp=(long long)jp*1000+prev;
        if(mp.find(kp)!=mp.end()){
            return mp[kp];
        }
        bool f1=check(st,jp+prev-1,prev-1,maxi,mp);
        bool f2=check(st,jp+prev,prev,maxi,mp);
        bool f3=check(st,jp+prev+1,prev+1,maxi,mp);
        

        return mp[kp]=f1||f2||f3;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        set<int>st;
        for(auto i:stones){
            st.insert(i);
        }
        // map<int,int>mp;
        // for(int i=0; i<n; i++){
        //     mp[stones[i]]=i;
        // }
        // vector<vector<int>>dp(stones.back(),vector<int>(stones.back(),-1));
        map<int,int>mp;
        return check(st,1,1,stones.back(),mp);
    }
};