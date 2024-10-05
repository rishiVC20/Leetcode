class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        sort(s1.begin(),s1.end());
        if(s2.size() < s1.size())
            return false;
        for(int i=0; i<s2.size()-n+1; i++){
            // cout<<s2[i]<<' ';
            string k=s2.substr(i,n);
            sort(k.begin(),k.end());
            if(k==s1)
                return true;
        }

        return false;
    }
};