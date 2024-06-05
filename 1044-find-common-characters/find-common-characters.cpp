class Solution {
public:
    vector<int> count(string &s)
    {
        vector<int>res(26,0);
        for (int i=0; i<s.size(); i++)
        {
            res[s[i]-'a']++;
        }

        return res;
    }

    vector<int> common(vector<int>&a, vector<int> b)
    {
        vector<int>st(26);
        for (int i=0; i<26; i++)
        {
            st[i] = min(a[i],b[i]);
        }

        return st;
    }

    vector<string> commonChars(vector<string>& words) {
        vector<int>ans = count(words[0]);

        for (int i=1; i<words.size(); i++)
        {
            ans = common(ans, count(words[i]));
        }

        vector<string>fin;
        for (int i=0; i<ans.size(); i++)
        {
            while (ans[i] > 0)
            {
                fin.push_back(string(1,'a'+i));
                ans[i]--;
            }
        }

        return fin;
    }
};