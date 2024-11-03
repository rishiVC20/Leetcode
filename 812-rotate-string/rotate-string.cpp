class Solution {
public:
    bool check(string s1, string s2, int p){
        int j=0;
        for(int i=p; i<s1.size(); i++){
            if(s1[i] != s2[j++])
                return false;
        }
        for(int i=0; i<p; i++){
            if(s1[i] != s2[j++])
                return false;
        }

        return true;
    }
    bool rotateString(string s, string goal) {
        int m=s.size();
        int n=goal.size();

        if(n!=m)
            return false;

        char p=goal[0];
        bool f=false;
        for(int i=0; i<m; i++){
            if(s[i] == p){
                f = f|check(s,goal,i);
            }
        }    

        return f;
    }
};