class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int cn=0;
        vector<int>a;
        set<int>st1,st2,st;
        for(int i=0; i<A.size(); i++){
            st1.insert(A[i]);
            st2.insert(B[i]);
            if(A[i]==B[i]){
                cn++;
                a.push_back(cn); 
                continue;
            }
            if(st1.find(B[i]) != st1.end())
                cn++;
            if(st2.find(A[i]) != st2.end())
                cn++;

            a.push_back(cn);        
        }

        return a;
    }
};