class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size(),m=board.size();
        auto check=[&](char ele,int row, int col)->bool{
            int cn=0;
            for(int i=0; i<9; i++){
                if(board[row][i]==ele){
                    cn++;
                }
            }
            if(cn>1){
                return false;
            }
            cn=0;
            for(int i=0; i<9; i++){
                if(board[i][col]==ele){
                    cn++;
                }
            }
            if(cn>1){
                return false;
            }
            int k1=row/3,k2=col/3;
            k1*=3,k2*=3;
            cn=0;
            for(int i=k1; i<(k1+3); i++){
                for(int j=k2; j<(k2+3); j++){
                    if(board[i][j]==ele){
                        cn++;
                    }
                }
            }
            if(cn>1){
                return false;
            }
            return true;
        };

        vector<pair<int,int>>v;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    //row col
                    v.push_back({i,j});
                }
            }
        }

        auto solve=[&](auto &self, int j)->bool{
            if(j==v.size()){
                return true;
            }
            // cout<<v

            // cout<<v[j].first<<' '<<v[j].second<<endl;
            if (check(board[v[j].first][v[j].second],v[j].first,v[j].second)){
                if(self(self,j+1)){
                    return true;
                }
            }

            return false;
        };

        return solve(solve,0);
    }
};