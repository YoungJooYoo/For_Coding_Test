class Solution 
{
public:
    vector<int> missingRolls(const vector<int> &rolls, const int mean, const int n)
    {
        const int m = rolls.size();
        const int totalRolls = m + n;
        const int observedSum = accumulate(rolls.begin(), rolls.end(), 0);
        const int missingSum = (mean * totalRolls) - observedSum;
        vector<int> result(n, MIN_DICE_VALUE);

        assert(m >= MIN_ROLLS_SIZE && m <= MAX_ROLLS_SIZE);
        assert(n >= MIN_MISSING_COUNT && n <= MAX_MISSING_COUNT);
        assert(mean >= MIN_DICE_VALUE && mean <= MAX_DICE_VALUE);
        
        if (missingSum < n || missingSum > n * MAX_ROLL_VALUE) // 누락된 n개의 관측값은 각 1 이상 6 이하여야 하므로, missingSum은 최소 n, 최대 n * MAX_ROLL_VALUE여야 함.
        {
            return vector<int>();  // 조건을 만족하는 배열이 없으면 빈 배열 반환
        }
        
        int remainingSum = missingSum - n;  // 이미 1씩 할당했으므로
        for (int i = 0; i < n && remainingSum > 0; ++i)
        {
            const int addition = min(MAX_ROLL_VALUE - MIN_DICE_VALUE, remainingSum);
            result[i] += addition;
            remainingSum -= addition;
        }
        
        return result;
    }

private:
    enum 
    {
        MIN_ROLLS_SIZE      = 1,
        MAX_ROLLS_SIZE      = 100000,  // 10^5
        MIN_MISSING_COUNT   = 1,
        MAX_MISSING_COUNT   = 100000,  // 10^5
        MIN_DICE_VALUE      = 1,
        MAX_DICE_VALUE      = 6,
        MAX_ROLL_VALUE      = 6       // 주사위 한 번의 결과 최대값
    };
};


// https://leetcode.com/problems/find-missing-observations/description/

/*


**2028. 누락된 관측값 찾기**  
*Medium*  
*Topics*  
*Companies*  
*Hint*

여섯 면체 주사위를 n + m번 던진 관측값이 있습니다. 각 면은 1부터 6까지의 숫자로 표시됩니다. 이 중 n개의 관측값이 누락되어, m개의 관측값만 가지고 있습니다. 다행히도, n + m번의 주사위 던지기의 평균값도 계산해 두었습니다.

길이 m인 정수 배열 **rolls**가 주어지며, **rolls[i]**는 i번째 관측값을 나타냅니다. 또한 정수 **mean**과 **n**이 주어집니다.

모든 n + m번의 주사위 던지기의 평균값이 정확히 **mean**이 되도록, 누락된 n개의 관측값을 담은 길이 n의 배열을 반환하세요.  
만약 조건을 만족하는 여러 가지 정답이 있다면 그 중 아무거나 반환하고, 조건을 만족하는 배열이 존재하지 않으면 빈 배열을 반환하세요.

참고:  
- k개의 숫자 집합의 평균값은 그 숫자들의 합을 k로 나눈 값입니다.
- **mean**은 정수이므로, n + m번의 주사위 던지기의 합은 n + m으로 나누어떨어져야 합니다.

---

**예제 1:**

- 입력: rolls = [3,2,4,3], mean = 4, n = 2  
- 출력: [6,6]  
- 설명: 전체 6번의 던지기의 합은 (3 + 2 + 4 + 3 + 6 + 6) = 24이며, 평균은 24 / 6 = 4입니다.

---

**예제 2:**

- 입력: rolls = [1,5,6], mean = 3, n = 4  
- 출력: [2,3,2,2]  
- 설명: 전체 7번의 던지기의 합은 (1 + 5 + 6 + 2 + 3 + 2 + 2) = 21이며, 평균은 21 / 7 = 3입니다.

---

**예제 3:**

- 입력: rolls = [1,2,3,4], mean = 6, n = 4  
- 출력: []  
- 설명: 어떤 4개의 누락된 관측값을 추가하더라도 전체 평균이 6이 될 수 없으므로, 빈 배열을 반환합니다.

---

**제약 조건:**

- m == rolls.length  
- 1 <= n, m <= 10^5  
- 1 <= rolls[i], mean <= 6

---

**힌트 1:**  
누락된 n개의 관측값의 합은 무엇이어야 하는지 생각해보세요.

**힌트 2:**  
각 누락된 관측값이 1 이상 6 이하인 배열을 생성할 수 있는지 고민해보세요.
*/
