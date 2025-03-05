class Solution {
public:
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> sequence(n * 2 - 1, 0); // 결과 시퀀스의 길이는 2*n - 1
        vector<bool> numberUsed(n + 1, false); // numberUsed[i]가 true면 숫자 i를 이미 사용한 상태임

        findLexicoLargestRecurive(0, sequence, numberUsed, n);

        return sequence;
    }

private:
    bool findLexicoLargestRecurive(int index, vector<int>& sequence, vector<bool>& numberUsed, const int targetNumber)
    {
        if (index == sequence.size())
        {
            return true;
        }
        else if (sequence[index] != 0) // 이미 채워진 위치는 건너뛰기
        {
            return findLexicoLargestRecurive(index + 1, sequence, numberUsed, targetNumber);
        }

        for (int num = targetNumber; num >= 1; --num) // targetNumber부터 1까지 숫자를 시도
        {
            if (numberUsed[num] == true)
            {
                continue;
            }

            numberUsed[num] = true; // 현재 숫자를 사용하고 자리 채우기
            sequence[index] = num;

            if (num == 1)
            {
                if (findLexicoLargestRecurive(index + 1, sequence, numberUsed, targetNumber) == true) // 1은 단 한 번만 등장해야 함
                {
                    return true;
                }
            }
            else if (index + num < sequence.size() && sequence[index + num] == 0)
            {
                sequence[index + num] = num; // 1 이외의 숫자는 두 군데에 배치되어야 함: index와 index + num
                if (findLexicoLargestRecurive(index + 1, sequence, numberUsed, targetNumber) == true)
                {
                    return true;
                }
                // 두 번째 배치 백트래킹
                sequence[index + num] = 0;
            }

            sequence[index] = 0; // 현재 배치 백트래킹
            numberUsed[num] = false;
        }

        return false;
    }
};

// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/?envType=daily-question&envId=2025-02-16

/*

다음은 문제 원문을 그대로 한국어로 번역한 내용입니다.

---

**1718. 사전 순으로 가장 큰 유효 수열 구성하기**  
*Medium*  
*Topics*  
*Companies*  
*Hint*

정수 **n**이 주어질 때, 다음 조건들을 모두 만족하는, 원소가 [1, n] 범위에 있는 수열을 구성하세요:

- 정수 1은 수열에 한 번만 나타납니다.
- 2부터 n 사이의 각 정수는 수열에 두 번 나타납니다.
- 2부터 n 사이의 모든 정수 i에 대해, i가 수열에서 두 번 등장하는 위치 사이의 거리는 정확히 i입니다.
  - 여기서, 수열에서 두 숫자 a[i]와 a[j] 사이의 거리는 두 인덱스의 차이 |j - i|로 정의됩니다.

위 조건들을 만족하는 수열들 중, 사전 순(lexicographically)으로 가장 큰 수열을 반환하세요.  
주어진 제약 조건 하에서는 항상 해답이 존재함이 보장됩니다.

사전 순으로 큰 수열의 정의:  
동일한 길이의 두 수열 a와 b가 있을 때, a와 b가 처음으로 서로 다른 위치에서, a의 원소가 b의 원소보다 크다면 a가 사전 순으로 더 큽니다.  
예를 들어, [0, 1, 9, 0]은 [0, 1, 5, 6]보다 사전 순으로 큰데, 그 이유는 두 수열이 처음으로 다른 위치인 세 번째 원소에서 9가 5보다 크기 때문입니다.

---

**예제 1:**

- **입력:** n = 3  
- **출력:** [3, 1, 2, 3, 2]  
- **설명:**  
  [2, 3, 2, 1, 3]도 유효한 수열이지만, [3, 1, 2, 3, 2]가 사전 순으로 더 큰 유효 수열입니다.

---

**예제 2:**

- **입력:** n = 5  
- **출력:** [5, 3, 1, 4, 3, 5, 2, 4, 2]

---

**제약 조건:**

- 1 <= n <= 20
*/
