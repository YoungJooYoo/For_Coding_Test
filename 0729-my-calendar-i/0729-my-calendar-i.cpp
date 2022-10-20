class MyCalendar {
public:
    map<int,int> m;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto p= m.upper_bound(start);
        if(p== m.end() || end <= p->second) 
        {
            m[end]=start;
            return true;
        } 
        return false;
    }
};