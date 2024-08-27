class Solution 
{
public:
    string categorizeBox(const int length, const int width, const int height, const int mass) 
    {
        const long long volume = static_cast<long long>(length) * width * height;
        
        const bool isBulky = length >= 10000 || width >= 10000 || height >= 10000 || volume >= 1000000000;
        const bool isHeavy = mass >= 100;

        if (isBulky && isHeavy) 
        {
            return "Both";
        }
        else if (isBulky) 
        {
            return "Bulky";
        }
        else if (isHeavy) 
        {
            return "Heavy";
        }
        else 
        {
            return "Neither";
        }
    }
};


// https://leetcode.com/problems/categorize-box-according-to-criteria/description/

/*

문제 2525. 기준에 따른 상자 분류

**난이도**: 쉬움

**문제 설명**:

네 개의 정수 `length`, `width`, `height`, `mass`가 주어집니다. 이 값들은 각각 상자의 길이, 너비, 높이, 질량을 나타냅니다. 이 상자의 분류를 나타내는 문자열을 반환하세요.

상자는 다음과 같은 기준에 따라 분류됩니다:

- **"Bulky"** (부피가 큰):
  - 상자의 어떤 치수라도 10^4 이상이거나,
  - 상자의 부피가 10^9 이상일 때
- **"Heavy"** (무거운):
  - 상자의 질량이 100 이상일 때
- **"Both"** (부피가 크고 무거운):
  - 상자가 "Bulky"이면서 "Heavy"일 때
- **"Neither"** (둘 다 아님):
  - 상자가 "Bulky"도 아니고 "Heavy"도 아닐 때
- **"Bulky"** (부피가 크지만 무겁지 않음):
  - 상자가 "Bulky"이지만 "Heavy"는 아닐 때
- **"Heavy"** (무겁지만 부피가 크지 않음):
  - 상자가 "Heavy"이지만 "Bulky"는 아닐 때

상자의 부피는 길이, 너비, 높이의 곱으로 계산됩니다.

**예제**:

예제 1:
- 입력: `length = 1000`, `width = 35`, `height = 700`, `mass = 300`
- 출력: `"Heavy"`
- 설명: 
  - 상자의 어떤 치수도 10^4 이상이 아닙니다.
  - 부피 = 24,500,000 <= 10^9 이므로 "Bulky"로 분류되지 않습니다.
  - 하지만 질량이 100 이상이므로 상자는 "Heavy"로 분류됩니다.
  - 따라서 상자는 "Bulky"는 아니지만 "Heavy"이므로 "Heavy"를 반환합니다.

예제 2:
- 입력: `length = 200`, `width = 50`, `height = 800`, `mass = 50`
- 출력: `"Neither"`
- 설명:
  - 상자의 어떤 치수도 10^4 이상이 아닙니다.
  - 부피 = 8 * 10^6 <= 10^9 이므로 "Bulky"로 분류되지 않습니다.
  - 질량도 100 미만이므로 "Heavy"로 분류되지 않습니다.
  - 따라서 상자는 두 분류에 해당하지 않으므로 "Neither"를 반환합니다.

**제약 조건**:
- `1 <= length, width, height <= 10^5`
- `1 <= mass <= 10^3`

*/
