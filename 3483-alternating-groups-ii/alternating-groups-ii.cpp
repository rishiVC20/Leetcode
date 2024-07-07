class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int>a(2*n);
        for (int i=0; i<n; i++){
            a[i] = colors[i];
            a[i+n] = colors[i];
        }

        int count = 1;
        int sum = 0;
        for (int i=1; i<n+k-1; i++){
            // cout<<i<<' ';
            if (a[i] != a[i-1])
                count++;
            else
                count = 1;
            // cout<<count<<' ';    
            if (count >= k)
                sum++;        
        }

        return sum;
    }
};