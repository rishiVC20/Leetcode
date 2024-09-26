class MyCalendar {
public:
    vector<pair<int,int>>v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0; i<v.size(); i++){
            // if(start>=v[i].first && start<v[i].second)
            //     return false;
            // if(end>v[i].first && end<=v[i].second)
            //     return false;
            if(start < v[i].second && end >v[i].first)
                return false;

        }
        v.push_back({start,end});

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */