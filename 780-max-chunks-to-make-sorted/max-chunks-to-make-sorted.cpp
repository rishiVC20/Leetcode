class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxi = 0;
        int ans = 0;
        for (int i=0; i<arr.size(); i++)
        {
            if (arr[i] > maxi)
                maxi = arr[i];
            if (maxi==i)
                ans++;    
        }

        return ans;
    }
};