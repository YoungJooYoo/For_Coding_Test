class Solution 
{
public:
    int isPrefixOfWord(const string& sentence, const string& searchWord) 
    {
        stringstream ss(sentence);
        string word;
        int i = 1;

        while (ss >> word)
        {
            if (word.substr(0, searchWord.size()) == searchWord)
            {
                return i;
            }
            ++i;
        }


        return FAIL;
    }

private:
    enum
    {
        FAIL = -1,
    };
};


// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/
/*
물론입니다! 다음은 LeetCode 문제 1455의 한국어 번역입니다:

---

### 1455. 단어가 문장의 어떤 단어의 접두사로 발생하는지 확인하기

**난이도: 쉬움**

#### 문제 설명

단어들이 단일 공백으로 구분된 문장과 `searchWord`가 주어집니다. `searchWord`가 문장의 어떤 단어의 접두사인지 확인하세요.

`searchWord`가 접두사인 단어가 문장에 있으면, 그 단어의 인덱스를 반환하세요 (1-인덱스 기준). `searchWord`가 여러 단어의 접두사인 경우, 첫 번째 단어의 인덱스를 반환하세요. 해당 단어가 없으면 -1을 반환하세요.

문자열 `s`의 접두사는 `s`의 선두에 있는 연속적인 부분 문자열입니다.

#### 예제

**예제 1**:

- 입력: `sentence = "i love eating burger"`, `searchWord = "burg"`
- 출력: `4`
- 설명: "burg"는 "burger"의 접두사로, 문장에서 4번째 단어입니다.

**예제 2**:

- 입력: `sentence = "this problem is an easy problem"`, `searchWord = "pro"`
- 출력: `2`
- 설명: "pro"는 "problem"의 접두사로, 문장에서 2번째와 6번째 단어입니다. 하지만 최소 인덱스인 2를 반환합니다.

**예제 3**:

- 입력: `sentence = "i am tired"`, `searchWord = "you"`
- 출력: `-1`
- 설명: "you"는 문장의 어떤 단어의 접두사도 아닙니다.

#### 제약 조건

- `1 <= sentence.length <= 100`
- `1 <= searchWord.length <= 10`
- `sentence`는 소문자 영어 문자와 공백으로 구성됩니다.
- `searchWord`는 소문자 영어 문자로 구성됩니다.

---
*/
