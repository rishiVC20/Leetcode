class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long>>pq;
        pq.push(1);
        set<long>st;
        st.insert(1);
        int curr;
        vector<long>a={2,3,5};
        for(long i=1; i<=n; i++){
            curr = pq.top();
            // cout<<curr<<' ';
            for(auto j:a){
                long t=curr*j;
                if(st.find(t)==st.end()){
                    st.insert(t);
                    pq.push(t);
                }
            }
            pq.pop();
        }

        return curr;
    }
};