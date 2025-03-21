class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(bound<=1){
            return {};
        }
        if(x==1 && y==1 && bound>=2){
            return {2};
        }
        if(x==1 || y==1){
            int mm=min(x,y);
            int mx=max(x,y);
            int d=log(bound-1)/log(mx);
            int pk=pow(mx,0);
            vector<int>df;
            int r=0;
            while(pk<bound){
                df.push_back(pk+1);
                r++;
                pk=pow(mx,r);
            }
            return df;
        }
        int maxi=1;
        // if(x!=1)
            maxi=log(bound-1)/log(x);
        int maxj=1;
        // if(y!=1)
            maxj=log(bound-1)/log(y);
        set<int>st;
        for(int i=0; i<=maxi; i++){
            int t=pow(x,i);
            int j=0;
            int g=t+pow(y,j);
            while(g <= bound){
                st.insert(g);
                j++;
                g=t+pow(y,j);
            }
        }
        for(int i=0; i<=maxj; i++){
            int t=pow(y,i);
            int j=0;
            int g=t+pow(x,j);
            while(g <= bound){
                st.insert(g);
                j++;
                g=t+pow(x,j);
            }
        }
        vector<int>ans;
        for(auto i:st){
            ans.push_back(i);
        }

        return ans;
    }
};