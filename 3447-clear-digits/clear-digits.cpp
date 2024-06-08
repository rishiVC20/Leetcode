class Solution {
public:
    string clearDigits(string s) {
        string ss = "";
        int n = s.size();
        int i=0; 
        while (i<n)
        {
            if (!isdigit(s[i])){
                ss += s[i];
                i++;
            }
            else{
                i++;
                if (ss.size()>0)
                    ss.pop_back();
            }
        }

        return ss;
    }
};