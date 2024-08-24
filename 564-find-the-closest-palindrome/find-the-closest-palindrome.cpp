class Solution {
public:
    long long solve(long long a, bool f){
        long long res=a;
        if(!f){
            a /= 10;
        }
        while(a>0){
            res = res*10+(a%10);
            a /= 10;
        }

        return res;
    }
    string nearestPalindromic(string n) {
        int m=n.size();
        bool f=(m%2==0);
        vector<long long>v;
        long long c=(m+1)/2;
        string ss = n.substr(0,c);
        long long g=stol(ss);
        long long bn=stol(n);
        if(m==1){
            int k=n[0]-'0';
            int j=k-1;
            return to_string(j);
        }
        //same number
        v.push_back(solve(g,f));
        
        //number+1
        v.push_back(solve(g+1,f));

        //number-1
        v.push_back(solve(g-1,f));

        //10 power - 1
        v.push_back(pow(10,m-1)-1);

        //10 power+1
        v.push_back(pow(10,m)+1);
        // for(auto i:v)
        //     cout<<i<<' ';
        long long diff=INT_MAX;
        long long d;
        for(auto i:v){
            if(i==bn)
                continue;
            long long j=abs(i-bn);
            if(j < diff){
                diff=j;
                d=i;
            }
            else if(j==diff){
                d=min(d,i);
            }
        }

        return to_string(d);
    }
};