class MyCalendar {
public:
    MyCalendar() 
    {
    }
    
    bool book(int start, int end) 
    {
        auto itr = days.upper_bound(start);
        
        if (itr == days.end() || end <= itr->second) { // start 체크, end 체크
            days[end] = start;
            return true;
        }
        
        return false;
    }

private:
    map<int, int> days;
};