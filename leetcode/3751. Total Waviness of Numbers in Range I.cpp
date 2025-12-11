using namespace std; 

class Solution 
{
public:
    int totalWaviness(const int num1, const int num2) const  
    {
        assert(MIN_NUM <= num1 && num1 <= MAX_NUM);
        assert(MIN_NUM <= num2 && num2 <= MAX_NUM);

        int totalWavinessSum = 0; 

        for (int num = num1; num <= num2; ++num)
        {
            const string strNum = to_string(num); 
            totalWavinessSum += calculateWavinessForSingleNumber(strNum);
        }

        assert(totalWavinessSum >= 0);
        return totalWavinessSum;
    }

private:

    int calculateWavinessForSingleNumber(const string& strNum) const
    {
        if (strNum.length() < MIN_WAVINESS_LENGTH)
        {
            return 0;
        }

        int wavinessCount = 0;

        for (size_t i = 1; i < strNum.length() - 1; ++i)
        {
            const int leftDigit = strNum[i - 1] - '0';
            const int currentDigit = strNum[i] - '0';
            const int rightDigit = strNum[i + 1] - '0';
            if ((currentDigit < leftDigit && currentDigit < rightDigit) || 
            (currentDigit > leftDigit && currentDigit > rightDigit))
            {
                ++wavinessCount; 
            }
            assert(0 <= leftDigit && leftDigit <= 9);
            assert(0 <= currentDigit && currentDigit <= 9);
            assert(0 <= rightDigit && rightDigit <= 9);
        }

        assert(wavinessCount >= 0);
        return wavinessCount;
    }

    enum
    {
        MIN_WAVINESS_LENGTH = 3,
        MIN_NUM = 1,           
        MAX_NUM = 100000,       
    };
};

// https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/description/

/*

## 3751. 범위 내 숫자들의 총 파동성 I

`num1`과 `num2` 두 정수가 주어지며, 이는 `[num1, num2]` (num1과 num2를 포함하는) 범위를 나타냅니다.

어떤 숫자의 **파동성(waviness)**은 해당 숫자의 **피크(peak)**와 **밸리(valley)**의 총 개수로 정의됩니다:

*   **피크(Peak)**: 어떤 자릿수가 양쪽 바로 옆에 있는 숫자들보다 엄격하게 클 때 피크입니다.
*   **밸리(Valley)**: 어떤 자릿수가 양쪽 바로 옆에 있는 숫자들보다 엄격하게 작을 때 밸리입니다.
*   숫자의 **첫 번째와 마지막 자릿수는 피크 또는 밸리가 될 수 없습니다.**
*   **3자리 미만의 숫자는 파동성이 0입니다.**

`[num1, num2]` 범위 내의 모든 숫자에 대한 파동성의 총합을 반환하세요.

**예제 1:**

**입력:** `num1 = 120`, `num2 = 130`
**출력:** 3
**설명:**
`[120, 130]` 범위에서:
*   `120`: 가운데 자릿수 `2`는 피크이며, 파동성 = 1.
*   `121`: 가운데 자릿수 `2`는 피크이며, 파동성 = 1.
*   `130`: 가운데 자릿수 `3`은 피크이며, 파동성 = 1.
범위 내의 다른 모든 숫자는 파동성이 0입니다.
따라서 총 파동성은 1 + 1 + 1 = 3입니다.

**예제 2:**

**입력:** `num1 = 198`, `num2 = 202`
**출력:** 3
**설명:**
`[198, 202]` 범위에서:
*   `198`: 가운데 자릿수 `9`는 피크이며, 파동성 = 1.
*   `201`: 가운데 자릿수 `0`은 밸리이며, 파동성 = 1.
*   `202`: 가운데 자릿수 `0`은 밸리이며, 파동성 = 1.
범위 내의 다른 모든 숫자는 파동성이 0입니다.
따라서 총 파동성은 1 + 1 + 1 = 3입니다.

**예제 3:**

**입력:** `num1 = 4848`, `num2 = 4848`
**출력:** 2
**설명:**
숫자 `4848`에서: 두 번째 자릿수 `8`은 피크이고, 세 번째 자릿수 `4`는 밸리이므로, 파동성은 2입니다.

**제약 조건:**

*   `1 <= num1 <= num2 <= 10^5`
*/
