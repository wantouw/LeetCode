class MyCalendarTwo {
public:
    // map<int, int> flags;
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlapped;

    MyCalendarTwo() {
        
    }

    bool isOverlapped(int newStart, int newEnd, int start, int end){
        if (max(start, newStart) < min(end, newEnd)){
            return true;
        }
        return false;
    }
    
    bool book(int start, int end) {
        for(pair<int, int> booking: overlapped){
            if(isOverlapped(booking.first, booking.second, start, end)){
                return false;
            }
        }

        for(pair<int, int> booking: bookings){
            if(isOverlapped(booking.first, booking.second, start, end)){
                overlapped.push_back(make_pair(max(start, booking.first), min(end, booking.second)));
            }
        }
        bookings.push_back(make_pair(start, end));

        return true;
    }


};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */