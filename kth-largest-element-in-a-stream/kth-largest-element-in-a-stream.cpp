class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; // 우선순위 큐
    int size;
    
    KthLargest(int k, vector<int> nums) 
    {
        size = k;
        for (auto x : nums) {
            pq.push(x);
        }
        while (pq.size() > k) {
            pq.pop();
        }

    }
    
    int add(int val) 
    {
        pq.push(val);
        if (pq.size() > size) {
            pq.pop();
        }
        
        return pq.top();
    }
};