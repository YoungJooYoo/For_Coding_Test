class TwoSum {
public:
    TwoSum() {}
    
    void add(int number) 
    {
        nums.insert(number);
    }
    
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

/* 
    아이디어 :  1 + 4 = 5    ->    4 = 5 - 1로 접근하기  
    4를 찾는중 5에서 무엇을떄뱌 4가 나오는지 찾는다.
    
    찾는 target이 4라고 가정을 하자.
    자료구조 nums에 저장된 자료에 순차 접근하면서
    
    {1 3 4 5 7} 저장 되어있다는 가정하에
    target(4) = 1 - *itr 접근
    
*/