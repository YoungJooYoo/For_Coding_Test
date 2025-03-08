class Solution {
public:
    vector<int> diffWaysToCompute(const string& expression)
    {
        vector<int> results;
        bool isPureNumber = true;

        // pure number case
        for (const char ch : expression)
        {
            if (isdigit(ch) == false)
            {
                isPureNumber = false;
                break;
            }
        }
        if (isPureNumber == true)
        {
            results.push_back(stoi(expression));
            return results;
        }

        // non-pure number case
        for (size_t i = 0; i < expression.size(); ++i) // expression을 순회하면서 연산자('+', '-', '*')를 찾습니다.
        {
            const char ch = expression[i];
            if (ch == '+' || ch == '-' || ch == '*')
            {
                const vector<int> leftResults = diffWaysToCompute(expression.substr(0, i)); // 연산자 기준으로 문자열을 왼쪽과 오른쪽으로 분할
                const vector<int> rightResults = diffWaysToCompute(expression.substr(i + 1));

                for (const int leftVal : leftResults) // 분할된 결과를 현재 연산자로 조합하여 결과 계산
                {
                    for (const int rightVal : rightResults)
                    {
                        int computedVal = 0;
                        switch (ch)
                        {
                            case '+': computedVal = leftVal + rightVal; break;
                            case '-': computedVal = leftVal - rightVal; break;
                            case '*': computedVal = leftVal * rightVal; break;
                            default: assert(false);
                        }
                        results.push_back(computedVal);
                    }
                }
            }
        }

        return results;
    }
};

// https://leetcode.com/problems/different-ways-to-add-parentheses/description/

/*

### 241. 다른 방식으로 괄호 추가하기
**중간 난이도**

**주제**

**기업**

숫자와 연산자로 이루어진 문자열 `expression`이 주어질 때, 
숫자와 연산자를 그룹화하는 모든 가능한 방법을 계산하여 가능한 모든 결과를 반환하세요. 
답은 어떤 순서로든 반환해도 됩니다.

테스트 케이스는 출력 값이 32비트 정수에 맞도록 생성되며, 
서로 다른 결과의 수는 10⁴을 넘지 않습니다.

#### 예제 1:

```
입력: expression = "2-1-1"
출력: [0,2]
```

**설명:**
- ((2-1)-1) = 0
- (2-(1-1)) = 2

#### 예제 2:

```
입력: expression = "2*3-4*5"
출력: [-34,-14,-10,-10,10]
```

**설명:**
- (2*(3-(4*5))) = -34
- ((2*3)-(4*5)) = -14
- ((2*(3-4))*5) = -10
- (2*((3-4)*5)) = -10
- (((2*3)-4)*5) = 10

#### 제약 사항:

- 1 <= `expression.length` <= 20
- `expression`은 숫자와 연산자 '+', '-', '*'으로 이루어져 있습니다.
- 입력 `expression`의 모든 정수 값은 [0, 99] 범위에 있습니다.

---

diffWaysToCompute("2-1-1")
├── (operator at index 1: '-')
│    ├── left: diffWaysToCompute("2")   --> [2]
│    └── right: diffWaysToCompute("1-1")
│            └── (operator at index 1: '-')
│                   ├── left: diffWaysToCompute("1")  --> [1]
│                   └── right: diffWaysToCompute("1") --> [1]
│                          └── Combine: 1 - 1 = 0  --> [0]
│            └── => [0]
│    └── Combine: for left=2 and right=0: 2 - 0 = 2  --> [2]
└── (operator at index 3: '-')
     ├── left: diffWaysToCompute("2-1")
     │        └── (operator at index 1: '-')
     │               ├── left: diffWaysToCompute("2")  --> [2]
     │               └── right: diffWaysToCompute("1") --> [1]
     │                      └── Combine: 2 - 1 = 1  --> [1]
     │        └── => [1]
     └── right: diffWaysToCompute("1")  --> [1]
     └── Combine: for left=1 and right=1: 1 - 1 = 0  --> [0]

*/
