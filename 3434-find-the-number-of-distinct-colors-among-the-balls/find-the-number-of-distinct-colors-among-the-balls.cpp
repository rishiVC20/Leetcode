class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int>m1,m2;

        vector<int>arr;
        int cn=0;
        for(int i=0; i<queries.size(); i++){
            int p=queries[i][0],q=queries[i][1];

            if(m1.find(p)!=m1.end()){
                int m=m1[p];
                m2[m]--;
                if(m2[m]==0){
                    cn--;
                }
                m1[p]=q;
                if(m2.find(q)!=m2.end()){
                    m2[q]++;
                    if(m2[q]==1)
                        cn++;
                }
                else{
                    m2[q]++;
                    cn++;
                }
            }
            else{
                m1[p]=q;
                if(m2.find(q)!=m2.end()){
                    m2[q]++;
                    if(m2[q]==1)
                        cn++;
                }
                else{
                    m2[q]++;
                    cn++;
                }
            }
            arr.push_back(cn);
        }

        return arr;
    }
};