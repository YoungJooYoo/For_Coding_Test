class MyHashSet {
private:
	int prime;
	vector<list<int>> table;

	int hash(int key) 
    {
		return key % prime;
	}

	list<int>::iterator search(int key) // 해당 원소가 있는 iterator를 반환 
    {
		int h = hash(key);
		return find(table[h].begin(), table[h].end(), key);
	}

public:
	MyHashSet() : prime(10007), table(prime) {}
	
	void add(int key) 
    {
		int h = hash(key);
		if (contains(key) == false) { // 해당 키가 존재하지 않으면, 키를 넣는다.
            table[h].push_back(key);
        }
	}
	
	void remove(int key) 
    {
		int h = hash(key);
		list<int>::iterator it = search(key);
		if (it != table[h].end()) { // 반복자가, table에 존재한다면 삭세 , 없다면 end반환
            table[h].erase(it);
        }
	}
	
	bool contains(int key) 
    {
		int h = hash(key);
		return search(key) != table[h].end();
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */