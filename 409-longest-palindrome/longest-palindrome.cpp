class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>a(26,0);
        vector<int>b(26,0);
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]-'a' >= 0)
                a[s[i]-'a']++;
            else
                b[s[i]-'A']++;    
        }

        int maxi = 0;
        int cn = 0;
        bool f = false;
        for (int i=0; i<26; i++)
        {
            if (a[i]%2 == 0)
            {
                cn += a[i];
            }
            else{
                // maxi = max(maxi,a[i]);
                cn += (a[i]-1);
                f = true;
            }
            

            if (b[i]%2 == 0)
            {
                cn += b[i];
            }
            else{
                // maxi = max(maxi,b[i]);
                cn += (b[i]-1);
                f = true;
            }
            

            // maxi = max(maxi,max(a[i],b[i]));
        }

        // cn += maxi;
        if (f)
            cn++;

        return cn;
    }
};