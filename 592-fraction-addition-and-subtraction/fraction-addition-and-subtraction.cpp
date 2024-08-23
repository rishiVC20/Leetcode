class Solution {
public:
    string fractionAddition(string expression) {
        int n=expression.size();
        bool f=false;
        vector<char>v;
        vector<pair<int,int>>a;
        for(int i=0; i<n; ){
            if(i==0 && expression[0]=='-'){
                    f=true;
                    v.push_back('-');
                    i++;
                    continue;
            }
            if(expression[i]=='-' || expression[i]=='+'){
                v.push_back(expression[i]);
                i++;
                continue;
            }

            long long j=0; 
            long long tt=0;   
            while(expression[i]!='/'){
                long long p=expression[i]-'0';
                j = j*10 + p;
                tt++;
                i++;
            }
            i++;
            long long k=0;
            tt=0;
            while( i<n && isdigit(expression[i])){
                long long p=expression[i]-'0';
                k = k*10 + p;
                tt++;
                i++;
            }
            a.push_back({j,k});
        }
        long long ss=1;
        for(auto i:a){
            long long k=i.second;
            ss *= k;
        }
        // cout<<f;
        for(auto i:v)
            cout<<i<<' ';
        long long sum=0;
        int b=0;
        for(int i=0; i<a.size(); i++){
            int p=ss/a[i].second;
            int j=a[i].first*p;
            // cout<<j<<' ';
            if(f){
                j *= -1;
                sum += j;
                f=false;
                b++;
                continue;
            }
            else if(i==0){
                sum+=j;
                continue;
            }
            // cout<<sum<<' ';
            // cout<<b<<' ';
            char h;
            if(b<v.size())
                h=v[b++];
            // cout<<h<<' ';
            if(h=='-'){
                j *= -1;
            }
            // cout<<j<<' ';
            sum += j;
        }
        // cout<<sum<<' ';
        if(sum==0){
            ss=1;
            return "0/1";
        }
        string s;
        if(sum<0){
            s += '-';
            sum=abs(sum);
        }
        if(sum%ss == 0){
            sum /= abs(ss);
            ss=1;
        }
        if(ss%sum == 0){
            ss /= abs(sum);
            sum=1;
        }
        // if(sum%2==0 && ss%2==0){
        //     sum /= 2;
        //     ss /= 2;
        // }
        // cout<<sum;
        int gg=__gcd(sum,ss);
        sum /= gg;
        ss /= gg;
        
        s += to_string(sum)+'/'+to_string(ss);

        return s;
    }
};