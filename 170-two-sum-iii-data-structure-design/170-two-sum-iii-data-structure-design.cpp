class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    multiset<long> s;
    /** Add the number to an internal data structure.. */
    void add(int number) {
        s.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto it = s.begin(); it != s.end();it++) {
            auto ptr = s.find(value - *it);
            if(ptr != s.end() && ptr != it )return true;
        }
        return false;
    }
};