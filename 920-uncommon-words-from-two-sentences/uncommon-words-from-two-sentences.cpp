class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>p1;
        vector<string>p2;
        for(int i=0; i<s1.size(); ){
            string p="";
            while(s1[i]!=' ' && i<s1.size()){
                p += s1[i];
                i++;
            }
            i++;
            p1.push_back(p);
        }
        for(int i=0; i<s2.size(); ){
            string p="";
            while(s2[i]!=' ' && i<s2.size()){
                p += s2[i];
                i++;
            }
            i++;
            p2.push_back(p);
        }
        map<string,int>m1;
        map<string,int>m2;
        for(auto i:p1)
            m1[i]++;
        for(auto i:p2)
            m2[i]++;
        vector<string>ans;    
        for(auto i:m1){
            if(i.second==1 && m2.find(i.first)==m2.end()){
                ans.push_back(i.first);
            }
        }
        for(auto i:m2){
            if(i.second==1 && m1.find(i.first)==m1.end()){
                ans.push_back(i.first);
            }
        }        

        return ans;
    }
};