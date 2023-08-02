class MyCircularQueue {
public:
    MyCircularQueue(int k): head(0), tail(0), curr_q_size(0), q_size(k), q(vector<int>(k, 0)) {}
       
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        q[tail] = value;
        tail++; 
        curr_q_size++;
        tail = tail % q_size; // tail 값은 항상 q의 사이즈에 맞는 인덱스만 나오게 한다.
        return true;
    }
    
    bool deQueue() {
        if(isEmpty() == true) {
            return false;
        }
        head++;
        head = head % q_size; // head 값은 항상 q의 사이즈에 맞는 인덱스만 나오게 한다.
        curr_q_size--;
        return true;
    }
    
    int Front() {
        if (isEmpty() == true) {
            return -1;
        }
        else {
            return q[head];
        }
    }
    
    int Rear() {
        if(curr_q_size == 0) { // 현재 큐가 비었다면 -1반환
            return -1;
        }
        if (tail == 0) { // 현재 큐 길이가 0이상일때 tail이 다시 큐의 맨 앞 온경우 배열의 마지막 값 반환
            return q[q_size - 1];
        }
        else { // 큐의 꼬리가 아직 앞으로 다시 돌아오지 않은 경우
            return q[tail - 1];
        }
    }
    
    bool isEmpty() {
        if (curr_q_size == 0) { // size 0이면 true, 0보다 크면 false
            return true;
        }
        else {
            return false;
        }
    }
    
    bool isFull() {
        if (curr_q_size == q_size) {
            return true;
        }
        else {
            return false;
        }
    }
    
private:
    int head; 
    int tail; 
    int curr_q_size;
    int q_size; 
    vector<int> q;    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */