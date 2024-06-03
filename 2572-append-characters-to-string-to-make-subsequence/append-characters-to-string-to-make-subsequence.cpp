class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0, j=0;
        int n=t.size(), m=s.size();
        while (i<n && j<m)
        {
            if (t[i]==s[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }

        // if (i==n-1)
        //     return 0;

        return n-i;    
    }
};