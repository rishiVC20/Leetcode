class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>st;
        int n=nums.size();
        for(auto i:nums){
            st.insert(i);
        }   

        int kp=0;
        for(int i=0; i<n; i++){
            set<int>dr;
            dr.insert(nums[i]);
            if(dr.size()==st.size()){
                kp++;
            }
            for(int j=i+1; j<n; j++){
                dr.insert(nums[j]);
                if(dr.size()==st.size()){
                    kp++;
                }
            }
        }

        return kp;
    }
};