class Solution {
public:
    int minimumDeletions(string s) {
        int cn = 0;
        int ans = 0;
        int n = s.size();
        for (int i=0; i<n; i++){
            if (s[i]=='b'){
                cn++;
            }
            else if (cn>0){
                ans++;
                cn--;
            }
        }

        return ans;
    }
};