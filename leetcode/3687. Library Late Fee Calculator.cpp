class Solution 
{
public:
    int lateFee(const vector<int>& daysLate) const
    {
        assert(MIN_LENGTH <= daysLate.size() && daysLate.size() <= MAX_LENGTH);

        int totalLateFee = 0;

        for (const int day : daysLate)
        {
            assert(MIN_LATE <= day && day <= MAX_LATE);
            if (day == 1)
            {
                ++totalLateFee;
            }
            else if (2 <= day && day <= 5)
            {
                totalLateFee += (2 * day);
            }
            else
            {
                totalLateFee += (3 * day);
            }
        }

        assert(totalLateFee > 0);
        return totalLateFee;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_LATE = 1,
        MAX_LATE = 100,
    };
};

// https://leetcode.com/problems/library-late-fee-calculator/description/

/*
### 3687. 도서관 연체료 계산기

정수 배열 `daysLate`가 주어지며, `daysLate[i]`는 `i`번째 책이 얼마나 늦게 반납되었는지를 나타냅니다.

연체료는 다음과 같이 계산됩니다:

*   `daysLate[i] == 1`인 경우, 연체료는 `1`입니다.
*   `2 <= daysLate[i] <= 5`인 경우, 연체료는 `2 * daysLate[i]`입니다.
*   `daysLate[i] > 5`인 경우, 연체료는 `3 * daysLate[i]`입니다.

모든 책에 대한 총 연체료를 반환하세요.

**예시 1:**

**입력:** `daysLate = [5,1,7]`
**출력:** `32`
**설명:**
*   `daysLate[0] = 5`: 연체료는 `2 * daysLate[0] = 2 * 5 = 10`입니다.
*   `daysLate[1] = 1`: 연체료는 `1`입니다.
*   `daysLate[2] = 7`: 연체료는 `3 * daysLate[2] = 3 * 7 = 21`입니다.
따라서 총 연체료는 `10 + 1 + 21 = 32`입니다.

**예시 2:**

**입력:** `daysLate = [1,1]`
**출력:** `2`
**설명:**
*   `daysLate[0] = 1`: 연체료는 `1`입니다.
*   `daysLate[1] = 1`: 연체료는 `1`입니다.
따라서 총 연체료는 `1 + 1 = 2`입니다.

**제약 조건:**

*   `1 <= daysLate.length <= 100`
*   `1 <= daysLate[i] <= 100`
*/
