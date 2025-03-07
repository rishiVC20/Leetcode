class Solution {
public:
    bool srch(int x){
        for(int i=2; i*i<=x; i++){
            if(x%i==0)
                return true;
        }
        return false;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>p;
        for(int i=left; i<=right; i++){
            if(i==1)
                continue;
            if(!srch(i)){
                p.push_back(i);
            }
            // if(p.size()==2)
            //     return p;
        }
        int num1=-1,num2=-1;
        int diff=INT_MAX;
        for(int i=1; i<(int)p.size(); i++){
            int k=p[i]-p[i-1];
            if(k<diff){
                diff=k;
                num2=p[i],num1=p[i-1];
            }
        }
        return {num1,num2};
    }
};