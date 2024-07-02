class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int m = nums1.size();
        vector<bool>vis(n,false);
        vector<int>c;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (nums1[i]==nums2[j] && !vis[j]){
                    c.push_back(nums1[i]);
                    vis[j] = true;
                    break;
                }
            }
        }

        return c;
    }
};