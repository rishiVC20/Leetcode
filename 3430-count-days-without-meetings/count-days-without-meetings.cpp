class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<int>a;
        vector<int>b;
        int n = meetings.size();
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
        int cn = 0;
        for (auto i:meetings)
        {
            a.push_back(i[0]);
            b.push_back(i[1]);
            // cn += (i[1]-i[0])+1;
        }

        cn += (a[0]-1);
        for (int i=1; i<n; i++)
        {
            if (a[i] <= b[i-1])
            {
                if (b[i] <= b[i-1])
                    b[i] = b[i-1];
            }
            else{
                cn += a[i] - b[i-1] - 1;
            }
        }

        cn += days - b[n-1];

        return cn;
    }
};