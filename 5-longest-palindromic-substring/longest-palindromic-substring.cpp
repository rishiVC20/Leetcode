class Solution {
public:
    bool checkPalin(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1){
            return s;
        }
        int mx=1;
        string d="";
        d.push_back(s[0]);
        for(int i=1; i<n; i++){
            int kp1=mx+1,kp2=mx+2;
            string d1="",d2="";
            int ind1=i-mx,ind2=i-mx-1;
            if(ind1>=0){
                d1=s.substr(ind1,mx+1);
                // mx=max(mx,mx+1);
                if(checkPalin(d1)){
                    mx=max(mx,mx+1);
                    d=d1;
                }
            }
            if(ind2>=0){
                d2=s.substr(ind2,mx+2);
                if(checkPalin(d2)){
                    mx=max(mx,mx+2);
                    d=d2;
                }
            }
        }

        return d;
    }
};