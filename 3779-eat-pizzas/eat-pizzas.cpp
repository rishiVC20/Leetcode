class Solution {
    #define ll long long
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.rbegin(),pizzas.rend());
        ll n=pizzas.size();
        ll t=n/4;
        ll p1=t/2+t%2;
        ll p2=t/2;

        ll cn=0;
        ll i=0;
        while(p1>0){
            cn+=pizzas[i];
            i++;
            p1--;
        }
        i++;
        while(p2>0){
            cn+=pizzas[i];
            i+=2;
            p2--;
        }

        return cn;
    }
};