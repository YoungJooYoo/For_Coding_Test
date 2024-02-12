class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {}
    
    void pushFront(const int val) 
    {
        mQueue.insert(mQueue.begin(), val);
    }
    
    void pushMiddle(const int val) 
    {
        mQueue.insert(mQueue.begin() + mQueue.size() / 2, val);
    }
    
    void pushBack(const int val) 
    {
        mQueue.push_back(val);
    }
    
    int popFront() 
    {
        if (mQueue.empty()) return -1;
        const int val = mQueue.front(); // 제거하기 전에 front 값을 저장
        mQueue.erase(mQueue.begin()); // 첫 번째 요소 제거
        return val;
    }
    
    int popMiddle() 
    {
        if (mQueue.empty()) return -1;
        const int index = (mQueue.size() - 1) / 2; // 중앙 요소의 인덱스 계산
        const int val = mQueue[index]; // 제거하기 전에 중앙 값을 저장
        mQueue.erase(mQueue.begin() + index); // 중앙 요소 제거
        return val;
    }
    
    int popBack() 
    {
        if (mQueue.empty()) return -1;
        const int val = mQueue.back(); // 제거하기 전에 back 값을 저장
        mQueue.pop_back(); // 마지막 요소 제거
        return val;
    }

private:
    vector<int> mQueue;
};

// https://leetcode.com/problems/design-front-middle-back-queue/description/
