class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cp=0;
        int mini=blocks.size();
        for(int i=0; i<k; i++){
            cp+=(blocks[i]=='W');
        }
        mini=min(mini,cp);
        int j=k,i=0;
        while(j<(int)blocks.size()){
            if(blocks[j]=='W'){
                cp++;
            }
            if(blocks[i]=='W'){
                cp--;
            }
            j++,i++;
            mini=min(mini,cp);
        }

        return mini;
    }
};