class HitCounter {
public:
    HitCounter() {}
    
    void hit(int timestamp) 
    {
        time_stamp_log.push_back(timestamp);
    }
    
    int getHits(int timestamp) 
    {
        int count = 0;
        int time_stamp_300 = timestamp - 300;
        for (int i = time_stamp_log.size() - 1; i >= 0; i--) {
            if (time_stamp_log[i] <= time_stamp_300 ) {
                return count;
            }
            count++;
        }
        
        return count;
    }
    
private:
    vector<int> time_stamp_log;
};