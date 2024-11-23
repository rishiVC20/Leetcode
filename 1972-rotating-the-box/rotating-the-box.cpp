class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size();

        for(int i=0; i<n; i++){
            for(int j=m-1; j>=0; j--){
                int k=j;
                if(box[i][k]=='#'){
                    while(k<m){
                        if(k+1<m && box[i][k+1]=='.'){
                            box[i][k+1]='#';
                            box[i][k]='.';
                        }
                        else{
                            break;
                        }
                        k++;
                    }
                }
            }
        }

        vector<vector<char>>ans(m,vector<char>(n));
        
        int i=0;
        while(i<m){
            int j=n-1;
            int p=0;
            while(j>=0){
                ans[i][p] = box[j][i];
                p++;
                j--;
            }
            i++;
        }
        // for(auto i:box){
        //     for(auto j:i)
        //         cout<<j<<' ';
        //     cout<<endl;    
        // }
        return ans;
    }
};