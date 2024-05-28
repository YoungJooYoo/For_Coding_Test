class Solution 
{
public:
    vector<string> findOcurrences(const string& text, const string& first, const string& second) 
    {
        stringstream ss(text); // input을 stream에 넣기
        string prevWord1;
        string prevWord2;
        string currentWord;
        vector<string> result;

        while (ss >> currentWord) // 띄어쓰기 단위, 단어 단위로 파싱
        {
            if (prevWord1 == first && prevWord2 == second) 
            {
                result.push_back(currentWord);
            }
            prevWord1 = prevWord2;
            prevWord2 = currentWord;
        }

        return result;
    }
};

// https://leetcode.com/problems/occurrences-after-bigram/

/*
### 1078. 빅그램 이후의 발생 단어들
**난이도: 쉬움**

### 문제 설명
두 개의 문자열 `first`와 `second`가 주어질 때, 텍스트에서 `first second third` 형태의 발생을 고려하세요. 여기서 `second`는 `first` 바로 뒤에 오고, `third`는 `second` 바로 뒤에 옵니다.

모든 `first second third`의 발생에서 `third` 단어를 배열로 반환하세요.

### 예제

**예제 1:**

- 입력: `text = "alice is a good girl she is a good student"`, `first = "a"`, `second = "good"`
- 출력: `["girl","student"]`

**예제 2:**

- 입력: `text = "we will we will rock you"`, `first = "we"`, `second = "will"`
- 출력: `["we","rock"]`

### 제약 조건

- `text.length`는 1 이상 1000 이하입니다.
- `text`는 소문자 영어 문자와 공백으로 구성됩니다.
- 텍스트의 모든 단어는 단일 공백으로 구분됩니다.
- `first.length`와 `second.length`는 1 이상 10 이하입니다.
- `first`와 `second`는 소문자 영어 문자로 구성됩니다.
*/
