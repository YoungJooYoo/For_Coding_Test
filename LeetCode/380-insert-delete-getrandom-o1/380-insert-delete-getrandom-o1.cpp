class RandomizedSet {
public:
    RandomizedSet() {}
    
    bool insert(int val) 
    {
        if (s.find(val) != s.end()) { // val을 찾은경우
            return false;
        }
        s.insert(val);
        return true;
    }
    
    bool remove(int val) 
    {
        if (s.find(val) == s.end()) { // val을 못 찾은경우
            return false;
        }
        s.erase(val);
        return true;
    }
    
    int getRandom() 
    {
        // set의 시작점부터, 랜덤한 거리를 간 값 반환
        return *next(s.begin(), rand() % s.size());
    }
    
private:
    unordered_set<int> s;
};