class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int n = rows*cols;
        vector<vector<int>>v(n,vector<int>(2));
        
        vector<vector<int>>a={{0,1},{1,0},{0,-1},{-1,0}};

        int count=1;
        int step=1;
        int k1=rStart;
        int k2=cStart;
        v[0][0]=k1,v[0][1]=k2;
        int index=0;
        // v.push_back(k1,k2)
        while(count<n){
            for(int i=0; i<2; i++){
                int dr=a[index%4][0];
                int dc=a[index%4][1];
                for (int j=0; j<step; j++){
                    k1 += dr;
                    k2 += dc;
                    if (k1>=0 && k1<rows && k2>=0 && k2<cols){
                        v[count][0]=k1;
                        v[count][1]=k2;
                        count++;
                    }
                }
                index++;
            }
            step++;
        }

        return v;
    }
};