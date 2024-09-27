class MyCalendarTwo {
public:
    map<int, int> flags;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        flags[start]++;
        flags[end]--;
        int tracker = 0;
        for(auto itr = flags.begin();itr!=flags.end();itr++){
            // cout << itr->first << ' ' << itr->second << endl;
            tracker+=itr->second;
            if(tracker >= 3){
                flags[start]--;
                flags[end]++;
                return false;
            }
        }
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */