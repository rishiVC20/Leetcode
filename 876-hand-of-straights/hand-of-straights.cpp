class Solution {
public:
    bool check(int i, vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        int cn = 1;
        int cc = hand[i] + 1;
        hand[i] = -1;
        i++;
        while (i < n && cn < groupSize)
        {
            if (cc == hand[i])
            {
                cc = hand[i]+1;
                cn++;
                hand[i] = -1;
            }
            i++;
        }

        return cn==groupSize;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n%groupSize != 0)
            return false;
        
        sort(hand.begin(),hand.end());

        for (int i=0; i<n; i++)
        {
            if (hand[i] >= 0)
            {
                // cout<<i<<" ";
                if (!check(i,hand,groupSize))
                    return false;
            }
            // for (auto i:hand)
            //     cout<<i<<" ";
            cout<<endl;    
        }

        return true;
    }
};