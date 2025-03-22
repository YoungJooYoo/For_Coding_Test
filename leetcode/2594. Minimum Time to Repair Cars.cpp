class Solution 
{
public:
    long long repairCars(const vector<int>& ranks, const int cars) const
    {
        assert(ranks.size() >= MIN_RANKS_SIZE && ranks.size() <= MAX_RANKS_SIZE);
        assert(cars >= MIN_CARS && cars <= MAX_CARS);
        
        long long left = 0;
        long long right = static_cast<long long>(*min_element(ranks.begin(), ranks.end())) * cars * cars;
        
        while (left < right)
        {
            const long long mid = left + ((right - left) / 2);
            if (canRepair(mid, ranks, cars) == true)
            {
                right = mid;
            }
            else 
            {
                left = mid + 1;
            }
        }
        
        return left;
    }

private:
    bool canRepair(const long long time, const vector<int>& ranks, const int cars) const
    {
        long long total = 0;
        for (const int r : ranks)
        {
            const long long carsRepaired = static_cast<long long>(floor(sqrt((long double)time / r))); // 정비사 한 명이 T분 동안 수리할 수 있는 자동차 수: floor(√(T / r))
            total += carsRepaired;
            if (total >= cars)
            {
                return true;
            }
        }

        return (total >= cars) ? true : false;
    }

    enum
    {
        MIN_RANK = 1,       // 정비사의 최소 등급
        MAX_RANK = 100,     // 정비사의 최대 등급
        MIN_CARS = 1,       // 자동차 최소 개수
        MAX_CARS = 1000000, // 자동차 최대 개수
        MIN_RANKS_SIZE = 1, // ranks 배열 최소 크기
        MAX_RANKS_SIZE = 100000 // ranks 배열 최대 크기
    };
};


// https://leetcode.com/problems/minimum-time-to-repair-cars/description/?envType=daily-question&envId=2025-03-16

/*



---

**2594. 자동차 수리를 위한 최소 시간**

**난이도:** 중간

**문제 설명:**  
정수 배열 **ranks**가 주어지며, 각 원소는 정비사의 등급을 나타냅니다.  
- **ranks[i]**는 i번째 정비사의 등급입니다.  
- 등급이 **r**인 정비사는 **r * n²** 분 동안 **n**대의 자동차를 수리할 수 있습니다.

또한, 정수 **cars**가 주어지며, 이는 수리를 기다리는 자동차의 총 대수를 나타냅니다.

모든 정비사가 동시에 작업할 수 있을 때, 모든 자동차를 수리하는 데 걸리는 최소 시간을 반환하세요.

---

**예제 1:**

- **입력:** ranks = [4,2,3,1], cars = 10  
- **출력:** 16  
- **설명:**  
  - 첫 번째 정비사는 2대의 자동차를 수리합니다. 필요한 시간은 4 * 2² = 16분입니다.  
  - 두 번째 정비사는 2대의 자동차를 수리합니다. 필요한 시간은 2 * 2² = 8분입니다.  
  - 세 번째 정비사는 2대의 자동차를 수리합니다. 필요한 시간은 3 * 2² = 12분입니다.  
  - 네 번째 정비사는 4대의 자동차를 수리합니다. 필요한 시간은 1 * 4² = 16분입니다.  
  자동차들을 16분보다 적은 시간에 모두 수리할 수 없음을 증명할 수 있습니다.

---

**예제 2:**

- **입력:** ranks = [5,1,8], cars = 6  
- **출력:** 16  
- **설명:**  
  - 첫 번째 정비사는 1대의 자동차를 수리합니다. 필요한 시간은 5 * 1² = 5분입니다.  
  - 두 번째 정비사는 4대의 자동차를 수리합니다. 필요한 시간은 1 * 4² = 16분입니다.  
  - 세 번째 정비사는 1대의 자동차를 수리합니다. 필요한 시간은 8 * 1² = 8분입니다.  
  자동차들을 16분보다 적은 시간에 모두 수리할 수 없음을 증명할 수 있습니다.

---

**제약 조건:**

- 1 <= ranks.length <= 10⁵  
- 1 <= ranks[i] <= 100  
- 1 <= cars <= 10⁶

---

**힌트:**

1. 미리 정해진 시간 내에 모든 자동차를 수리할 수 있는지 확인할 수 있을까요?  
2. 답에 대해 이진 탐색을 적용해보세요.
*/
