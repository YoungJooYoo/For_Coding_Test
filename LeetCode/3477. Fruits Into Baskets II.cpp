class Solution 
{
public:
    int numOfUnplacedFruits(const vector<int>& fruits, vector<int>& baskets) const
    {
        const size_t fruitCount = fruits.size();
        int unplacedCount = 0;

        for (size_t i = 0; i < fruitCount; ++i)
        {
            const int fruitQuantity = fruits[i];
            bool isPlaced = false;
            
            for (auto& basketCapacity : baskets)
            {
                if (basketCapacity == VISITED)
                {
                    continue;
                }
                else if (fruitQuantity <= basketCapacity)
                {
                    basketCapacity = VISITED;
                    isPlaced = true;
                    break;
                }
            }
            
            if (!isPlaced)
            {
                ++unplacedCount;
            } 
        }

        return unplacedCount;
    }

private:
    enum
    {
        VISITED = -1,
    };
};


// https://leetcode.com/problems/fruits-into-baskets-ii/description/

/*

**3477. 바구니에 과일 담기 II  
난이도: Easy**

**문제 설명**  
정수 배열 fruits와 baskets가 주어지며, 두 배열의 길이는 n입니다.  
- fruits[i]는 i번째 종류의 과일의 수량을 나타내고,  
- baskets[j]는 j번째 바구니의 용량을 나타냅니다.

왼쪽에서 오른쪽으로 다음 규칙에 따라 과일을 배치합니다:

1. 각 과일 종류는 해당 과일의 수량보다 크거나 같은 용량을 가진 가장 왼쪽에 있는 사용 가능한 바구니에 배치해야 합니다.
2. 각 바구니는 단 하나의 과일 종류만 담을 수 있습니다.
3. 만약 어떤 과일 종류가 어떤 바구니에도 배치될 수 없다면, 그 과일은 배치되지 않습니다.

모든 가능한 배치가 이루어진 후, 배치되지 않은 과일 종류의 개수를 반환하세요.

---

**예제 1:**

- **입력:** fruits = [4, 2, 5], baskets = [3, 5, 4]  
- **출력:** 1  
- **설명:**  
  - fruits[0] = 4는 baskets[1] = 5에 배치됩니다.  
  - fruits[1] = 2는 baskets[0] = 3에 배치됩니다.  
  - fruits[2] = 5는 baskets[2] = 4의 용량이 부족하여 배치되지 않습니다.  
  - 따라서, 배치되지 않은 과일 종류는 1개이므로 1을 반환합니다.

---

**예제 2:**

- **입력:** fruits = [3, 6, 1], baskets = [6, 4, 7]  
- **출력:** 0  
- **설명:**  
  - fruits[0] = 3은 baskets[0] = 6에 배치됩니다.  
  - fruits[1] = 6은 baskets[1] = 4는 용량이 부족하여 배치되지 않지만, 다음 사용 가능한 baskets[2] = 7에 배치됩니다.  
  - fruits[2] = 1은 baskets[1] = 4에 배치됩니다.  
  - 모든 과일이 성공적으로 배치되었으므로 0을 반환합니다.

---

**제약 조건:**

- n == fruits.length == baskets.length  
- 1 <= n <= 100  
- 1 <= fruits[i], baskets[i] <= 1000

---
*/
