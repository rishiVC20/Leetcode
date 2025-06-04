class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1){
            return word;
        }
        int len=word.size()-(numFriends-1);
        string maxi="a";
        for(int i=0; i<word.size(); i++){
            string sub;
            if(i+len>=word.size()){
                sub=word.substr(i);
            }
            else{
                sub=word.substr(i,len);
            }
            maxi=max(maxi,sub);
        }

        return maxi;

    }
};