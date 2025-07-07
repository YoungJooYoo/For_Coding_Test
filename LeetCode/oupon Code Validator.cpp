class Solution 
{
public:
    vector<string> validateCoupons(const vector<string>& code, const vector<string>& businessLine, const vector<bool>& isActive) const 
    {
        assert(code.size() == businessLine.size());
        assert(code.size() == isActive.size());
        assert(MIN_N <= code.size() && code.size() <= MAX_N);

        const size_t LENGTH = code.size();
        vector<pair<string, string>> validCoupons;  // {businessLine, code}
        vector<string> result;

        for (size_t i = 0; i < LENGTH; ++i)
        {
            assert(code[i].size() <= MAX_STR_LENGTH);
            assert(businessLine[i].size() <= MAX_STR_LENGTH);
            if (isActive[i] == true && isValidCode(code[i]) == true && isValidBusinessLine(businessLine[i]) == true)
            {
                validCoupons.emplace_back(businessLine[i], code[i]);
            }
        }

        sort(validCoupons.begin(), validCoupons.end(), couponCompare);
        for (const auto& coupon : validCoupons)
        {
            result.push_back(coupon.second);
        }

        return result;
    }

private:
    bool isValidCode(const string& s) const
    {
        if (s.empty() == true)
        {
            return false;
        }
        for (const char ch : s)
        {
            if (isalnum(ch) == false && ch != '_')
            {
                return false;
            }
        }
        
        return true;
    }

    bool isValidBusinessLine(const string& s) const
    {
        return (businessPriority.find(s) != businessPriority.end()) ? true : false;
    }

    enum
    {
        MIN_N = 1,
        MAX_N = 100,
        MAX_STR_LENGTH = 100
    };

    static const unordered_map<string, int> businessPriority;

    static bool couponCompare(const pair<string, string>& a, const pair<string, string>& b)
    {
        const int priA = businessPriority.at(a.first);
        const int priB = businessPriority.at(b.first);
        if (priA != priB)
        {
            return (priA < priB) ? true : false;
        }
        return (a.second < b.second) ? true : false;
    }
};

const unordered_map<string, int> Solution::businessPriority =
{
    {"electronics", 0},
    {"grocery", 1},
    {"pharmacy", 2},
    {"restaurant", 3}
};


// https://leetcode.com/problems/coupon-code-validator/description/

/*
**문제 3606. 쿠폰 코드 유효성 검사기**
쉬움

---

총 `n`개의 쿠폰이 있으며, 세 개의 길이 `n` 배열로 각 쿠폰의 속성이 주어집니다:

* `code`: 문자열, 쿠폰의 식별자
* `businessLine`: 문자열, 쿠폰이 속한 업종
* `isActive`: boolean, 해당 쿠폰이 현재 활성 상태인지 여부

각 i번째 쿠폰의 속성은 다음과 같습니다:

* `code[i]`: 쿠폰 코드
* `businessLine[i]`: 쿠폰 업종
* `isActive[i]`: 활성 여부

쿠폰이 **유효**하려면 아래 조건을 모두 만족해야 합니다:
1️⃣ `code[i]`가 비어 있지 않고, 알파벳(a-z, A-Z), 숫자(0-9), 밑줄(\_)로만 이루어져 있어야 합니다.
2️⃣ `businessLine[i]`는 `"electronics"`, `"grocery"`, `"pharmacy"`, `"restaurant"` 중 하나여야 합니다.
3️⃣ `isActive[i]`가 true여야 합니다.

---

✅ **반환값**
모든 유효한 쿠폰의 `code`를 담은 배열을 반환하세요.
단, 정렬 기준은 다음과 같습니다:

* `businessLine` 순서: `"electronics"` < `"grocery"` < `"pharmacy"` < `"restaurant"`
* 같은 업종 내에서는 `code`를 사전순(오름차순)으로 정렬

---

## 예시 1

```
입력: 
code = ["SAVE20","","PHARMA5","SAVE@20"]
businessLine = ["restaurant","grocery","pharmacy","restaurant"]
isActive = [true,true,true,true]

출력: ["PHARMA5","SAVE20"]
```

**설명:**

* 1번 쿠폰(SAVE20): 유효
* 2번 쿠폰: 코드 비어 있음 → 무효
* 3번 쿠폰(PHARMA5): 유효
* 4번 쿠폰(SAVE\@20): 특수문자 @ → 무효

---

## 예시 2

```
입력: 
code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"]
businessLine = ["grocery","electronics","invalid"]
isActive = [false,true,true]

출력: ["ELECTRONICS_50"]
```

**설명:**

* 1번: 비활성 → 무효
* 2번: 유효
* 3번: 업종 invalid → 무효

---

## 제약사항

* `n == code.length == businessLine.length == isActive.length`
* 1 ≤ n ≤ 100
* 0 ≤ code\[i].length, businessLine\[i].length ≤ 100
* `code[i]`, `businessLine[i]`는 ASCII 출력 가능한 문자로 구성
* `isActive[i]`는 true 또는 false

---

**힌트**

* 조건을 만족하지 않는 쿠폰 필터링
* `(businessLine, code)` 쌍으로 관리
* `businessLine` 우선순위 맵 사용: `{"electronics":0, "grocery":1, "pharmacy":2, "restaurant":3}`
* 이 우선순위와 code로 정렬 후 code 배열 반환

*/
