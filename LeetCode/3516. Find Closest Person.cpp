class Solution 
{
public:
    int findClosest(const int x, const int y, const int z) const 
    {
        const int distancePerson1 = abs(z - x);
        const int distancePerson2 = abs(y - z);

        if (distancePerson1 < distancePerson2)
        {
            return 1;
        }
        else if (distancePerson1 > distancePerson2)
        {
            return 2;
        }

        return 0;
    }
};

// https://leetcode.com/problems/find-closest-person/description/

/*


**3516. 가장 가까운 사람 찾기**

**난이도:** 쉬움

**문제 설명:**  
세 정수 x, y, z가 주어지며, 이들은 수직선 상에서 세 사람의 위치를 나타냅니다.

- x는 사람 1의 위치입니다.
- y는 사람 2의 위치입니다.
- z는 움직이지 않는 사람 3의 위치입니다.

사람 1과 사람 2는 모두 같은 속도로 사람 3을 향해 이동합니다.

어느 사람이 사람 3에 먼저 도달하는지 결정하세요.

- 사람 1이 먼저 도달하면 1을 반환합니다.
- 사람 2가 먼저 도달하면 2를 반환합니다.
- 두 사람이 동시에 도달하면 0을 반환합니다.

---

**예제 1:**

- **입력:** x = 2, y = 7, z = 4
- **출력:** 1
- **설명:**  
  사람 1은 위치 2에서 시작하여 사람 3(위치 4)까지 2만큼 이동합니다.  
  사람 2는 위치 7에서 시작하여 사람 3까지 3만큼 이동하므로, 사람 1이 먼저 도착합니다.

---

**예제 2:**

- **입력:** x = 2, y = 5, z = 6
- **출력:** 2
- **설명:**  
  사람 1은 위치 2에서 사람 3(위치 6)까지 4만큼 이동합니다.  
  사람 2는 위치 5에서 시작하여 사람 3까지 1만큼 이동하므로, 사람 2가 먼저 도착합니다.

---

**예제 3:**

- **입력:** x = 1, y = 5, z = 3
- **출력:** 0
- **설명:**  
  사람 1은 위치 1에서 사람 3(위치 3)까지 2만큼 이동하고,  
  사람 2는 위치 5에서 사람 3까지 2만큼 이동하므로 두 사람이 동시에 도착합니다.

---

**제약 조건:**

- 1 <= x, y, z <= 100

---

이 문제의 핵심은 각 사람이 사람 3에 도달하기 위해 이동해야 하는 거리를 비교하는 것입니다.
*/
