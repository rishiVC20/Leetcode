class ProductOfNumbers {
public:
    vector<int>cn;
    vector<int>a;
    int prod=1;
    int j=0;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        cn.push_back(num);
        // if(num!=0){
        //     prod*=num;
        //     a.push_back(prod);
        // }
        // else{
        //     a.push_back(a.back());
        // }
    }
    
    int getProduct(int k) {
        int d=1;
        int m=cn.size()-k-1;
        for(int i=cn.size()-1; i>m; i--){
            // if(a[i])
            d*=cn[i];
        }
        return d;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */