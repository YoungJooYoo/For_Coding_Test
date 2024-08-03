class Solution 
{
public:
    vector<int> constructRectangle(const int area) 
    {
        int length = 0;
        int width = 0;
        int minDiff = INT_MAX;

        for (int i = 1; i * i <= area; ++i) 
        {
            if (area % i == 0) 
            {
                const int j = area / i;
                if (abs(i - j) < minDiff) 
                {
                    length = max(i, j);
                    width = min(i, j);
                    minDiff = abs(i - j);
                }
            }
        }

        return {length, width};
    }
};

// https://leetcode.com/problems/construct-the-rectangle/description/

/*

### 492. 직사각형 만들기

**난이도: 쉬움**

#### 문제 설명

웹 개발자는 웹 페이지의 크기를 디자인하는 방법을 알아야 합니다. 주어진 특정 직사각형 웹 페이지의 면적이 있을 때, 여러분의 작업은 다음 요구사항을 만족하는 직사각형 웹 페이지를 디자인하는 것입니다:

1. 디자인한 직사각형 웹 페이지의 면적이 주어진 목표 면적과 같아야 합니다.
2. 너비 \( W \)는 길이 \( L \)보다 크지 않아야 하므로, \( L \geq W \)이어야 합니다.
3. 길이 \( L \)과 너비 \( W \)의 차이가 가능한 한 작아야 합니다.

이제 여러분이 디자인한 웹 페이지의 길이 \( L \)과 너비 \( W \)를 순서대로 배열 \([L, W]\)로 반환하세요.

#### 예제

**예제 1**:

- **입력**: `area = 4`
- **출력**: `[2,2]`
- **설명**: 목표 면적은 4이며, 이를 구성할 수 있는 모든 방법은 \([1,4], [2,2], [4,1]\)입니다. 
  그러나 요구사항 2에 따라 \([1,4]\)는 불가능하고, 요구사항 3에 따라 \([4,1]\)은 \([2,2]\)보다 최적이 아닙니다. 따라서 길이 \( L \)은 2이고 너비 \( W \)는 2입니다.

**예제 2**:

- **입력**: `area = 37`
- **출력**: `[37,1]`

**예제 3**:

- **입력**: `area = 122122`
- **출력**: `[427,286]`

#### 제약 조건

- \( 1 \leq area \leq 10^7 \)

*/
