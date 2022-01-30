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
        for (auto itr = nums.begin(); itr != nums.end(); itr++) {
            auto ptr = nums.find(value - *itr);
            if (ptr != nums.end() && ptr != itr) {
                return true;
            }
        }
        
        return false;
    }
    
    private:
    multiset<long> nums; // 중복이 허용되는 자료구조 set
};