class LRUCache {
public:
    LRUCache(int capacity) : cache_capacity(capacity) {}
    
    int get(int key) 
    {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        q.push(key);
        cache[key]++;
        
        return m[key];
    }
    
    void put(int key, int value) 
    {
        q.push(key);
        cache[key]++;
        m[key] = value;
        
        while (cache.size() > cache_capacity) {
            int cur = q.front(); q.pop(); // LRU 특성상 앞부분부터 제거
            if ((cache[cur]--) == 1) { // 호출 1번밖에 안된 cache를 제거
                cache.erase(cur);
            }
        }
    }
    
private:
    unordered_map <int, int> m; // key - value 자료구조, 들어오는 모든 inpput 저장
    unordered_map <int, int> cache; // cache사이즈가 일정하게 유지, 호출된 횟수기록 빈도기록
    queue <int> q; // get or put 호출한 순서를 기록
    size_t cache_capacity;
};