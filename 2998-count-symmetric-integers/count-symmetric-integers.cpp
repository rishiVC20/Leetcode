class Solution {
public:
    bool cal(int p){
        string s=to_string(p);
        if(s.size()&1)
            return false;
        int c1=0,c2=0;
        for(int i=0; i<s.size()/2; i++){
            c1+=(s[i]-'0');
        }    
        for(int i=s.size()/2; i<s.size(); i++){
            c2+=(s[i]-'0');
        }
        return c1==c2;
    }
    int countSymmetricIntegers(int low, int high) {
        int k=0;
        for(int i=low; i<=high;  i++){
            k+=(cal(i)==true);
        }
        return k;
    }
};