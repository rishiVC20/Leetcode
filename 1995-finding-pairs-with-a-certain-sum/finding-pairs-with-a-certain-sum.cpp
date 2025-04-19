class FindSumPairs {
public:
    vector<int>a,b;
    map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a=nums1,b=nums2;
        for(auto i:b){
            mp[i]++;
        }
    }
    
    void add(int index, int val) {
        mp[b[index]]--;
        b[index]+=val;
        mp[b[index]]++;
    }
    
    int count(int tot) {
        int cn=0;
        for(int i=0; i<a.size(); i++){
            int p=tot-a[i];
            if(mp.find(p)!=mp.end() && mp[p]>0){
                cn+=mp[p];
            }
        }

        return cn;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */