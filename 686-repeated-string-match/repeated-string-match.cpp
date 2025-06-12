class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string cont=a;
        int sz=a.size();
        int sum=1;
        while(a.size()<b.size()){
            a+=cont;
            sum++;
        }

        sum++,a+=cont;
        int chr=-1;
        for(int i=0; i<a.size()-sz; i++){
            string see=a.substr(i,b.size());
            if(see==b){
                chr=i+b.size()-1;
                break;
            }
        }
        cout<<sum<<' '<<chr;
        if(chr==-1){
            return -1;
        }
        if(chr<a.size()-sz){
            return sum-1;
        }

        return sum;
    }
};