class Logger {
public:
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) 
    {
        if (log.find(message) != log.end()) {
            if (timestamp - log[message] < 10) {
                return false;
            }
            else {
                log[message] = timestamp;
            }
        }
        else {
            log[message] = timestamp;
        }
        
        return true;
    }
    
private:
    unordered_map<string, int> log;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */