class Solution {
public:
    bool check(vector<vector<char>> &mat, int row, int col){
        int r=row,c=col;
        while(c>=0){
            if(mat[r][c]=='Q'){
                return false;
            }
            c--;
        }
        r=row,c=col;
        while(r>=0 && c>=0){
            if(mat[r][c]=='Q'){
                return false;
            }
            r--,c--;
        }
        r=row,c=col;
        int n=mat.size();
        while(r<n && c>=0){
            if(mat[r][c]=='Q'){
                return false;
            }
            r++,c--;
        }

        return true;
    }
    int totalNQueens(int n) {
        map<vector<vector<char>>,int>v;
        int cn=0;
        vector<vector<char>>arr(n,vector<char>(n,'.'));
        auto solve=[&](auto &self, int col)->void{
            if(col==n){
                // v.insert(arr);
                v[arr]++;
                // if(exists(arr,))
                return;
            }

            for(int i=0; i<n; i++){
                if(check(arr,i,col)){
                    arr[i][col]='Q';
                    self(self,col+1);
                    arr[i][col]='.';
                }
            }
        };

        solve(solve,0);

        return v.size();

    }
};