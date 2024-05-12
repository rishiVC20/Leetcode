class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int>a(26,-1);
        vector<int>b(26,-1);
        int n=s.size();
        for (int i=0; i<n; i++){
            a[s[i]-'a']=i;
            b[t[i]-'a']=i;
        }
        int diff=0;
        for (int i=0; i<26; i++){
            if (a[i]!=-1 && b[i]!=-1){
                diff += abs(a[i]-b[i]);
            }
        }
        return diff;
    }
};