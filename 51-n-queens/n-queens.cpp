class Solution {
public:
    bool check(int row, int col, vector<vector<string>> &v){
        int x=row, y=col;
        //same row
        while (y>=0){
            if (v[x][y]=="Q")
                return false;
            y--;    
        }
        x=row, y=col;
        //diagonal upper left
        while (x>=0 && y>=0){
            if (v[x][y]=="Q")
                return false;
            x--, y--;    
        }
        int n=v.size();
        x=row,y=col;
        //diagonal lower left
        while (x<n && y>=0){
            if (v[x][y]=="Q")
                return false;
            x++, y--;    
        }

        return true;
    }
    void putAns(vector<vector<string>>&v, vector<vector<string>>&ans){
        vector<string>d;
        int p=v.size();
        for (int i=0; i<p; i++){
            string s="";
            for (int j=0; j<p; j++){
                s += v[i][j];
            }
            d.push_back(s);
        }
        ans.push_back(d);
    }
    void solve(int col, vector<vector<string>>&ans, vector<vector<string>>& v,int n){
        if (col==n){
            // cout<<'l';
            putAns(v,ans);
            return;
        }

        for (int i=0; i<n; i++){
            if (check(i,col,v)){
                v[i][col]="Q";
                solve(col+1,ans,v,n);
                v[i][col]=".";
            }
        }    
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<string>>v(n,vector<string>(n,"."));
        solve(0,ans,v,n);

        return ans;
    }
};