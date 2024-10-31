class Solution 
{
public:
    int repeatedStringMatch(const string& a, const string& b) 
    {
        const int minRepeats = b.size() / a.size();
        int count = 1;
        string repeatedStr = a;

        for (int i = 0; i <= minRepeats + 1; ++i) 
        {
            if (repeatedStr.find(b) != string::npos) 
            {
                return count;
            }
            repeatedStr += a;
            ++count;
        }

        return -1;
    }
};

// https://leetcode.com/problems/repeated-string-match/description/?envType=problem-list-v2&envId=string

/*


**686. 반복된 문자열 일치**  
난이도: 중간

주제: 문자열, 그리디, 브루트 포스

---

두 문자열 `a`와 `b`가 주어질 때, 문자열 `b`가 문자열 `a`의 반복된 부분 문자열로 포함되도록 하기 위해 `a`를 최소 몇 번 반복해야 하는지 반환하세요. 만약 `b`가 반복된 `a`의 부분 문자열이 될 수 없다면 `-1`을 반환하세요.

참고: 문자열 `"abc"`를 0번 반복하면 `""`, 1번 반복하면 `"abc"`, 2번 반복하면 `"abcabc"`입니다.

---

### 예제 1:

입력: 
```
a = "abcd", b = "cdabcdab"
```
출력: 
```
3
```
설명: `a`를 세 번 반복한 `"abcdabcdabcd"`에서 `b`가 부분 문자열로 포함되므로 `3`을 반환합니다.

### 예제 2:

입력: 
```
a = "a", b = "aa"
```
출력: 
```
2
```

---

### 제약 사항:

- `1 <= a.length, b.length <= 10^4`
- `a`와 `b`는 소문자 영어 문자로 구성되어 있습니다.
*/
