class Solution {
public:
    string compressedString(string word) {
        int curr=1;
        int n=word.size();
        string s="";
        for(int i=1; i<n; i++){
            if(word[i]==word[i-1]){
                curr++;
            }
            if(curr==9){
                s += '9';
                s += word[i];
                curr=0;
                continue;
            }
            else if(word[i]!=word[i-1]){
                if(curr != 0){
                    s += (curr+'0');
                    s += (word[i-1]);
                }
                curr=1;
            }
        }
        if(curr != 0){
            s += (curr+'0');
            s += (word[n-1]);
        }

        return s;
    }
};