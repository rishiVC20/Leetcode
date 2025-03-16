class Spreadsheet {
public:
    vector<vector<int>>a;
    Spreadsheet(int rows) {
        a.resize(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int p=cell[0]-'A';
        string d=cell.substr(1);
        int r=stoi(d);
        r--;
        a[r][p]=value;
    }
    
    void resetCell(string cell) {
        int p=cell[0]-'A';
        string d=cell.substr(1);
        int r;
        if(d.size()>0){
           r=stoi(d);
           r--;
        }
        a[r][p]=0;
    }
    
    int getValue(string formula) {
        int fir,sec;
        int i=0;
        string s1,s2;
        while(formula[i]!='+'){
            i++;
        }
        s1=formula.substr(1,i-1);
        s2=formula.substr(i+1);
        if(s1[0]>='A' && s1[0]<='Z'){
            int p=s1[0]-'A';
            string d=s1.substr(1);
            int r;
            if(d.size()>0){
                r=stoi(d);
                r--;
            }
            fir=a[r][p];
        }
        else{
            fir=stoi(s1);
        }
        if(s2[0]>='A' && s2[0]<='Z'){
            int p=s2[0]-'A';
            string d=s2.substr(1);
            int r;
            if(d.size()>0){
                r=stoi(d);
                r--;
            }
            sec=a[r][p];
        }
        else{
            sec=stoi(s2);
        }

        return fir+sec;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */