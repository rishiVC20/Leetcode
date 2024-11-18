class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    map<int,int>mp;
    bool book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;
        int cn=0;
        for(auto i:mp){
            cn += i.second;
            if(cn>=3){
                mp[startTime]--;
                mp[endTime]++;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */