class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        int n=sentence.size(),m=searchWord.size();
        int cp=0;
        for(int i=0; i<n; i++){
            if(i==0 || sentence[i-1]==' '){
                cp++;
                if(i+m <= n){
                    string s=sentence.substr(i,m);
                    if(s==searchWord)
                        return cp; 
                }
            }
        }

        return -1;
    }
};