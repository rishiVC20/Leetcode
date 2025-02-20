class Solution {
public:
    void f(string &z, vector<string> &a, int n){
        if(z.size()==n){
            a.push_back(z);
            return;
        }
        if(z.size()==0 || z.back()=='b' || z.back()=='c'){
            z.push_back('a');
            f(z,a,n);
            z.pop_back();
        }
        if(z.size()==0 || z.back()=='a' || z.back()=='c'){
            z.push_back('b');
            f(z,a,n);
            z.pop_back();
        }
        if(z.size()==0 || z.back()=='a' || z.back()=='b'){
            z.push_back('c');
            f(z,a,n);
            z.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string>a;
        string z="";
        f(z,a,n);
        if(a.size()<k)
            return "";

        return a[k-1];    
    }
};