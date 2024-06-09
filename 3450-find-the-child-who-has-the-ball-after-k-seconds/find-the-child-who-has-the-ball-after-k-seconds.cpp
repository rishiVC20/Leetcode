class Solution {
public:
    int numberOfChild(int n, int k) {
        int p = k/(n-1);
        int q = k%(n-1);

        if (p%2 == 0)
        {
            return q;
        }
        else{
            return (n-1)-q;
        }

        return 1;
    }
};