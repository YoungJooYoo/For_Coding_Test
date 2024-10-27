class Solution 
{
public:
    int possibleStringCount(const string& word) 
    {
        const size_t LENGTH = word.size();
        int count = 1;

        for (size_t i = 0; i < LENGTH - 1; ++i)
        {
            if (word[i] == word[i + 1])
            {
                ++count;
            }
        }

        return count;
    }
};


// https://leetcode.com/problems/find-the-original-typed-string-i/description/

/*



### 3330. 원래 타이핑한 문자열 찾기 I

**힌트**

Alice는 컴퓨터에서 특정 문자열을 타이핑하려고 시도하고 있습니다. 
그러나 그녀는 키를 너무 오래 눌러 하나의 문자가 여러 번 입력되는 실수를 할 수 있습니다.

Alice는 타이핑에 집중하려고 노력했지만, 여전히 이러한 실수를 최대 한 번 했을 수도 있음을 알고 있습니다.

문자열 `word`가 주어지며, 이는 Alice의 화면에 표시된 최종 출력입니다.

Alice가 의도했을 수 있는 원래 문자열의 총 개수를 반환하세요.

---

#### 예제 1:

```
입력: word = "abbcccc"
출력: 5
설명:
가능한 원래 문자열은 다음과 같습니다: "abbcccc", "abbccc", "abbcc", "abbc", "abcccc".
```

---

#### 예제 2:

```
입력: word = "abcd"
출력: 1
설명:
가능한 원래 문자열은 "abcd" 하나뿐입니다.
```

---

#### 예제 3:

```
입력: word = "aaaa"
출력: 4
```

---

#### 제약 사항:

- `1 <= word.length <= 100`
- `word`는 소문자 영어 문자로만 구성됩니다.

---

### 📝 **힌트**

문자열 `word`에서 연속된 동일 문자가 최대 한 번만 반복되었는지 확인하세요. 원래 문자열을 찾기 위해 각 문자 그룹에서 반복을 최소화하는 방법을 고려해야 합니다.

---


*/
