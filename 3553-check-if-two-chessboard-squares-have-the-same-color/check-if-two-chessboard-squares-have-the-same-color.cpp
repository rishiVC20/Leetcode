class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int c1=coordinate1[0]-'a';
        int c2=coordinate2[0]-'a';
        if(abs(c1-c2)%2==0){
            int p1=coordinate1[1]-'0';
            int p2=coordinate2[1]-'0';
            if(abs(p1-p2)%2==0)
                return true;
            return false;    
        }
        else{
            int p1=coordinate1[1]-'0';
            int p2=coordinate2[1]-'0';
            if(abs(p1-p2)%2==0)
                return false;
            return true;   
        }
        
    }
};