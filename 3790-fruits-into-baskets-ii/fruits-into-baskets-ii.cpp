class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<int>v(fruits.size(),-1);
        int t=0;
        for(int i=0; i<fruits.size(); i++){
            bool f=false;
            for(int j=0; j<fruits.size(); j++){
                if(baskets[j]>=fruits[i] && v[j]==-1){
                    v[j]=0;
                    f=true;
                    break;
                }
            }
            if(!f)
                t++;
        }

        return t;
    }
};