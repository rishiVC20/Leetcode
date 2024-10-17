class Solution {
public:
    int maximumSwap(int num) {
        string g=to_string(num);
        bool f=false;
        for(int i=0; i<g.size(); i++){
            int m=-1;
            for(int j=i+1; j<g.size(); j++){
                char c1=g[i],c2=g[j];
                if(c1 < c2){
                    if(m != -1){
                        if(c2 >= g[m]){
                            m=j;
                        }
                    }
                    else{
                        m=j;
                    }
                    f=true;
                }
            }
            if(f){
                swap(g[i],g[m]);
                break;
            }
        }
        int ans=stoi(g);

        return ans;
    }
};