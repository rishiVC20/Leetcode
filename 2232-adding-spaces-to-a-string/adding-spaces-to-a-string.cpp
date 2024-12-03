class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int k=0;

        string sp="";
        int n=spaces.size();
        int t=s.size();
        int j=0;
        for(int i=0; i<t; i++){
            if(k<n && i==spaces[k]){
                sp+=' ';
                k++;
            }
            sp+=s[i];
        }

        return sp;
    }
};