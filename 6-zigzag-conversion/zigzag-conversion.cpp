class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        int x=n;

        int col=0;
        while(x>0){
            x-=numRows;
            col++;
            if(x>0){
                int k=numRows-2;
                if(k<0)
                    continue;
                if(x>=k){
                    x-=k;
                    col+=k;
                }
                else if(k>=0){
                    col+=k;
                    x=0;
                }
                else{
                    break;
                }
            }
        }
        vector<vector<char>>v(numRows,vector<char>(col,'0'));

        int st=0,cp=0;
        int chr=0;
        while(chr<n){
            for(int i=0; i<numRows; i++){
                v[i][cp]=s[chr];
                chr++;
                if(chr==n)
                    break;
            }
            cp++;
            st=numRows-2;
            // chr+=numRows;
            while(st>=1 && chr<n){
                v[st][cp]=s[chr];
                st--;
                cp++;
                chr++;
                if(chr==n)
                    break;
            }
        }

        string ans="";
        for(auto i:v){
            for(auto j:i){
                if(j!='0'){
                    ans+=j;
                }
                // cout<<j<<' ';
            }
            // cout<<endl;
        }

        return ans;
    }
};