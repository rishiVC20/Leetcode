class Solution {
public:
    vector<int>par;
    vector<int>rank;
    int cn;
    void solve(int x,int y){
        int p=find(x);
        int q=find(y);
        if (p!=q){
            if (rank[p]>rank[q]){
                par[q]=p;
            }
            else if (rank[p]<rank[q]){
                par[p]=q;
            }
            else{
                par[p]=q;
                rank[q]++;
            }
        }
        else{
            cn++;
        }
    } 
    int find(int x){
        if (par[x]==x)
            return x;
        int temp=find(par[x]);
        par[x]=temp;
        return temp;    
    }
    int regionsBySlashes(vector<string>& grid) {
       int n = grid.size();
        cn=1;
        int ss=n+1;
        par.resize(ss*ss);
        rank.resize(ss*ss);
        for (int i=0; i<par.size(); i++){
            par[i]=i;
            rank[i]=1;
        }
        for (int i=0; i<ss; i++){
            for (int j=0; j<ss; j++){
                if (i==0 || j==0 || i==ss-1 || j==ss-1){
                    int cp=ss*i+j;
                    if (cp!=0)
                        solve(0,cp);
                }
            }
        }
        for (int i=0; i<n; i++){
            string c=grid[i];
            for (int j=0; j<c.size(); j++){
                if (c[j]=='/'){
                    int c1=(i+1)*ss+j;
                    int c2=(i)*ss+(j+1);
                    solve(c1,c2);
                }
                else if (c[j]=='\\'){
                    int c1=(i+1)*ss+(j+1);
                    int c2=i*ss+j;
                    solve(c1,c2);
                }
            }
        }

        return cn; 
    }
};