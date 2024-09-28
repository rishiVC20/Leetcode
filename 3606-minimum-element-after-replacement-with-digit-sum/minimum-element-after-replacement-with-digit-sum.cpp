class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<int>v;
        for(auto i:nums){
            int k=i;
            int m=0;
            while(k){
                m += k%10;
                k /= 10;
            }
            v.push_back(m);
        }

        return *min_element(v.begin(),v.end());
    }
};