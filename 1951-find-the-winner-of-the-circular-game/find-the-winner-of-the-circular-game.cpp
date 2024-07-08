class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i=1; i<=n; i++){
            q.push(i);
        }

        while (q.size() > 1){
            int n = 1;
            while (q.size() > 1 && n<k){
                int a = q.front();
                q.pop();
                q.push(a);
                n++;
            }
            q.pop();
        }

        return q.front();
    }
};