class Solution
{    
public:
    vector<int> findPermutation(const string& s) const 
    {
        assert(MIN_LENGTH <= s.size() && s.size() <= MAX_LENGTH);

        vector<int> result(s.size() + 1);
        const size_t LENGTH = s.size();

        for (size_t i = 0; i < LENGTH + 1; ++i)
        {
            result[i] = i + 1;
        }

        for (size_t i = 0; i < LENGTH; ++i)
        {
            assert('D' == s[i] or 'I' == s[i]);
            size_t start = i;
            while (i < LENGTH && s[i] == 'D')
            {
                ++i;
            }
            reverse(result.begin() + start, result.begin() + i + 1); // D구간 [start, i]를 reverse (i는 D가 끝난 직후)
        }

        assert(result.size() == s.size() + 1);
        return result;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,
    };
};


/*


## 484. 순열 찾기 (Find Permutation)

### 문제 설명

정수 **n**개(1부터 n까지)의 모든 순열 **perm**이 있을 때,
길이 **n-1**의 문자열 **s**로 다음과 같이 표현할 수 있습니다:

* `s[i] == 'I'`라면, perm\[i] < perm\[i + 1]
  (즉, i번째 수가 그 다음 수보다 작으면 I)
* `s[i] == 'D'`라면, perm\[i] > perm\[i + 1]
  (즉, i번째 수가 그 다음 수보다 크면 D)

**문자열 s**가 주어질 때,
이를 만족하는 **가장 사전순으로 작은 순열 perm**을 찾아서 반환하세요.

---

### 예시

#### 예시 1

* 입력: `s = "I"`
* 출력: `[1, 2]`
* 설명: 1 < 2 이므로 유일한 순열입니다.

#### 예시 2

* 입력: `s = "DI"`
* 출력: `[2, 1, 3]`
* 설명:

  * \[2, 1, 3] → 2 > 1 (D), 1 < 3 (I)
  * \[3, 1, 2]도 "DI"가 되지만,
    사전순으로 더 작은 \[2, 1, 3]을 반환해야 합니다.

---

### 제약 사항

* 1 <= s.length <= 100,000
* s\[i]는 'I' 또는 'D'입니다.

---

### 추가 정보

* 실제 면접에서 출제된 적 있음
* 주제: 배열, 문자열, 스택, 그리디



*/
