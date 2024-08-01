class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int sum = 0;
        for (int i=0; i<n; i++){
            if ((details[i][11]=='6' && details[i][12]=='0')){
                continue;
            }
            if (details[i][11]>='6' && details[i][12]>='0')
                sum++;
        }

        return sum;
    }
};