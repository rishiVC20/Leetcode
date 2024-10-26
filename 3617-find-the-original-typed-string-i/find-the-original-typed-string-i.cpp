class Solution {
public:
    int possibleStringCount(string word) {
        int curr=1;
        int n=word.size();
        int cn=0;
        for(int i=1; i<n; i++){
            if(word[i]==word[i-1]){
                curr++;
            }
            else{
                // cout<<i<<' ';
                if(curr>1){
                    cn += curr-1;
                }
                curr=1;
            }

        }
        if(curr>1)
            cn += curr-1;

        return cn+1;
    }
};