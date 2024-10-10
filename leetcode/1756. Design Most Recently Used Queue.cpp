class MRUQueue 
{
public:
    MRUQueue(const int n) 
    {
        assert(n > 0);

        for (size_t i = 1; i <= n; ++i)
        {
            mArray.push_back(i);
        }
    }
    
    int fetch(const int k)
    {
        assert(mArray.size() >= k);
        
        const int num = mArray[k - 1];

        if (num == mArray.back())
        {
            return num;
        }
        else
        {
            mArray.erase(mArray.begin() + (k - 1));
            mArray.push_back(num);
            return num;
        }
    }

private:
    vector<int> mArray;
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */

// https://leetcode.com/problems/design-most-recently-used-queue/description/

 /*
 
 1756. 가장 최근에 사용된 요소 큐 설계
중간 난이도

주제

기업

가장 최근에 사용된 요소를 큐의 끝으로 이동시키는 큐와 유사한 데이터 구조를 설계하세요.

MRUQueue 클래스를 구현하세요:

MRUQueue(int n)는 n개의 요소를 가진 MRUQueue를 구성합니다: [1,2,3,...,n].
int fetch(int k)는 k번째 요소(1-인덱스)를 큐의 끝으로 이동시키고, 그 요소의 값을 반환합니다.
예제 1:
less
코드 복사
입력:
["MRUQueue", "fetch", "fetch", "fetch", "fetch"]
[[8], [3], [5], [2], [8]]
출력:
[null, 3, 6, 2, 2]
설명:

MRUQueue mRUQueue = new MRUQueue(8);
큐를 [1,2,3,4,5,6,7,8]로 초기화합니다.
mRUQueue.fetch(3);
3번째 요소(3)를 큐의 끝으로 이동시켜 큐를 [1,2,4,5,6,7,8,3]으로 만듭니다.
반환 값: 3
mRUQueue.fetch(5);
5번째 요소(6)를 큐의 끝으로 이동시켜 큐를 [1,2,4,5,7,8,3,6]으로 만듭니다.
반환 값: 6
mRUQueue.fetch(2);
2번째 요소(2)를 큐의 끝으로 이동시켜 큐를 [1,4,5,7,8,3,6,2]으로 만듭니다.
반환 값: 2
mRUQueue.fetch(8);
8번째 요소(2)는 이미 큐의 끝에 있으므로, 그대로 반환합니다.
반환 값: 2
제약 사항:
1 <= n <= 2000
1 <= k <= n
fetch 함수는 최대 2000번 호출됩니다.
추가 질문:
Follow up: 각 fetch 호출에 대해 O(n) 알고리즘을 찾는 것은 약간 쉽습니다. 각 fetch 호출에 대해 더 나은 복잡도를 가진 알고리즘을 찾을 수 있습니까?


 */
