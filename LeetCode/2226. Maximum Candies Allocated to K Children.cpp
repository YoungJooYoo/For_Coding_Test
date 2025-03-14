class Solution 
{
public:
    int maximumCandies(const vector<int>& candies, const long long k) 
    {
        assert(candies.size() >= MIN_CANDIES_COUNT && candies.size() <= MAX_CANDIES_COUNT);
        assert(k >= MIN_K && k <= MAX_K);

        int low = 1;
        int high = *max_element(candies.begin(), candies.end());
        int answer = 0;
        
        while (low <= high)
        {
            const int mid = low + (high - low) / 2; // mid: 각 아이가 받는 후보 사탕 수
            long long totalPiles = 0;
            for (const int candy : candies)
            {
                assert(candy >= MIN_CANDY && candy <= MAX_CANDY);
                totalPiles += candy / mid;
                if (totalPiles >= k)
                {
                    break;
                }
            }
            
            if (totalPiles >= k)
            {
                answer = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return answer;
    }
private:
    enum
    {
        MIN_CANDIES_COUNT = 1,
        MAX_CANDIES_COUNT = 100000,
        MIN_CANDY         = 1,
        MAX_CANDY         = 10000000,
        MIN_K             = 1,
        MAX_K             = 1000000000000LL
    };
};


// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/?envType=daily-question&envId=2025-03-14

/*


**2226. K명의 아이들에게 배분할 수 있는 최대 사탕 수**

**난이도:** 중간

**문제 설명:**  
0-indexed 정수 배열 **candies**가 주어집니다. 배열의 각 원소 **candies[i]**는 해당 사탕 더미의 사탕 개수를 나타냅니다. 각 사탕 더미를 여러 개의 하위 더미로 나눌 수는 있으나, 서로 다른 두 더미를 합칠 수는 없습니다.

또한 정수 **k**가 주어집니다. k명의 아이들에게 사탕 더미를 배분하는데, 각 아이는 동일한 개수의 사탕을 받아야 합니다. 단, 각 아이는 단 하나의 사탕 더미에서만 사탕을 배분받을 수 있으며, 일부 사탕 더미는 사용되지 않을 수 있습니다.

각 아이가 받을 수 있는 사탕의 최대 개수를 반환하세요.

---

**예제 1:**

- **입력:** candies = [5, 8, 6], k = 3  
- **출력:** 5  
- **설명:**  
  candies[1]의 사탕 더미를 크기 5와 3으로 나누고, candies[2]의 사탕 더미를 크기 5와 1로 나눕니다.  
  그러면 5, 5, 3, 5, 1 크기의 사탕 더미가 생기며, 이 중 5의 크기를 가진 3개의 더미를 각각 3명의 아이에게 배분할 수 있습니다.  
  각 아이가 5개 이상의 사탕을 받도록 하는 것은 불가능함이 증명됩니다.

---

**예제 2:**

- **입력:** candies = [2, 5], k = 11  
- **출력:** 0  
- **설명:**  
  아이는 11명이지만, 전체 사탕의 총 개수가 7개이므로 각 아이에게 최소한 1개 이상의 사탕을 배분할 수 없습니다.  
  따라서 각 아이는 사탕을 받지 못하여 답은 0입니다.

---

**제약 조건:**

- 1 <= candies.length <= 10^5  
- 1 <= candies[i] <= 10^7  
- 1 <= k <= 10^12

---

**힌트:**

1. **고정 사탕 개수 c**에 대해, 각 아이에게 c개의 사탕을 줄 수 있는지 확인하는 방법을 고민해보세요.
2. 이진 탐색을 사용하여 정답인 최대 c를 찾아낼 수 있습니다.

---

이와 같이 문제를 이해하고 접근하면, 이진 탐색을 활용하여 각 아이가 받을 수 있는 사탕의 최대 개수를 효율적으로 구할 수 있습니다.
*/
