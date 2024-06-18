class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>a;
        int n = numbers.size();
        for (int i=0; i<n; i++)
        {
            int k = target - numbers[i];
            int x = upper_bound(numbers.begin(),numbers.end(),k)-numbers.begin();
            x--;
            if (x<n && numbers[x]+numbers[i]==target){
                // a.push_back(i+1);
                // a.push_back(x+1);
                return {i+1,x+1};
                break;
            }
        }

        return {};
    }
};