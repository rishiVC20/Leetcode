class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();    
        int i=0, j=n-1;
        vector<double>a;
        while (i<j){
            double avg = ((double)nums[i] + (double)nums[j])/2;
            cout<<avg<<' ';
            a.push_back(avg);
            i++;
            j--;
        }
        sort(a.begin(),a.end());

        return a[0];
    }
};