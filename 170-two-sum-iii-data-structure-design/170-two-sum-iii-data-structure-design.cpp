class TwoSum {
public:
    TwoSum() {}
    
    void add(int number) 
    {
        nums.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value)
    {
        for (auto it = nums.begin(); it != nums.end(); it++) {
            auto ptr = nums.find(value - *it);
            if(ptr != nums.end() && ptr != it )return true;
        }
        
        return false;
    }
    
    private:
    multiset<long> nums; // 중복이 허용되는 자료구조 set
};