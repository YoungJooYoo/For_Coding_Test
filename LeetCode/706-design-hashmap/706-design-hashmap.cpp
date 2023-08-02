class MyHashMap {
public:
    int hash_map[1000001];
    
    MyHashMap() 
    {
        memset(hash_map, -1, sizeof(hash_map));    
    }
    
    void put(int key, int value) 
    {
        hash_map[key] = value;
    }
    
    int get(int key) 
    {
        return hash_map[key];
    }
    
    void remove(int key) 
    {
        hash_map[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */