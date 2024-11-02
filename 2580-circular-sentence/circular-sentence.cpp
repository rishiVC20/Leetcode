class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n=sentence.size();

        if(sentence[0] != sentence[n-1])
            return false;

        bool f=true;
        for(int i=0; i<n; i++){
            if(isalpha(sentence[i]))
                continue;

            if(sentence[i]==' '){
                if(sentence[i-1] != sentence[i+1]){
                    f=false;
                    break;
                }
            }    
        }    

        return f;
    }
};