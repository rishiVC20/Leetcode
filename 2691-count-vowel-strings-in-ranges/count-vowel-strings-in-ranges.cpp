class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>pre;
        set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        for(int i=0; i<words.size(); i++){
            string s=words[i];
            if(st.find(s[0])!=st.end() && st.find(s[s.size()-1])!=st.end()){
                if(pre.size()==0){
                    pre.push_back(1);
                    continue;
                }
                else{
                    pre.push_back(pre.back()+1);
                }
            }
            else{
                if(pre.size()==0){
                    pre.push_back(0);
                }
                else{
                    pre.push_back(pre.back());
                }
            }
        }
        vector<int>ans;

        for(int i=0; i<queries.size(); i++){
            int u=queries[i][0],v=queries[i][1];
            if(u==0){
                ans.push_back(pre[v]);
            }
            else{
                ans.push_back(pre[v]-pre[u-1]);
            }
        }

        return ans;
    }
};