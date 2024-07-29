class Solution 
{
public:
    long long pickGifts(const vector<int>& gifts, const int k) 
    {
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        long long result = 0;

        for (int i = 0; i < k; ++i) 
        {
            const int maxGifts = maxHeap.top(); // 최대값 추출
            maxHeap.pop();
            const int remainingGifts = static_cast<int>(sqrt(maxGifts)); // 제곱근의 바닥 값
            maxHeap.push(remainingGifts); // 남겨둔 선물 다시 삽입
        }

        while (!maxHeap.empty()) 
        {
            result += maxHeap.top();
            maxHeap.pop();
        }

        return result;
    }
};

// https://leetcode.com/problems/take-gifts-from-the-richest-pile/

/*
### 2558. 가장 많은 선물을 가진 더미에서 선물 가져가기

**난이도: 쉬움**

#### 문제 설명
정수 배열 `gifts`가 주어집니다. 이 배열은 다양한 더미에 있는 선물의 수를 나타냅니다. 매 초마다 다음과 같은 작업을 수행합니다:

1. 선물이 가장 많은 더미를 선택합니다.
   - 만약 선물이 가장 많은 더미가 여러 개 있다면, 아무거나 선택합니다.
2. 해당 더미에서 선물의 개수의 제곱근의 바닥 값을 남겨둡니다. 나머지 선물을 가져갑니다.

`k`초 후에 남아있는 선물의 총 개수를 반환하세요.

#### 예제

**예제 1**:
- 입력: `gifts = [25,64,9,4,100]`, `k = 4`
- 출력: `29`
- 설명:
  - 첫 번째 초에, 마지막 더미를 선택하여 10개의 선물을 남겨둡니다.
  - 두 번째 초에, 두 번째 더미를 선택하여 8개의 선물을 남겨둡니다.
  - 세 번째 초에, 첫 번째 더미를 선택하여 5개의 선물을 남겨둡니다.
  - 네 번째 초에, 마지막 더미를 다시 선택하여 3개의 선물을 남겨둡니다.
  - 최종적으로 남아있는 선물은 `[5,8,9,4,3]`이고, 총 남은 선물의 수는 29개입니다.

**예제 2**:
- 입력: `gifts = [1,1,1,1]`, `k = 4`
- 출력: `4`
- 설명:
  - 이 경우, 어떤 더미를 선택하든 각 더미에 1개의 선물을 남겨둡니다. 따라서 선물을 가져갈 수 없습니다.
  - 총 남은 선물의 수는 4개입니다.

#### 제약 조건
- `1 <= gifts.length <= 103`
- `1 <= gifts[i] <= 109`
- `1 <= k <= 103`
*/
