class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long n=0;
        long long sum=0;
        for(auto i:chalk)
            sum += i;
        long long v=k%sum;
        while(v>0){
            if(v>=chalk[n])
                v -= chalk[n];
            else
                break;    
            n++;
            n=n%chalk.size();
        }

        return (int)n;
    }
};