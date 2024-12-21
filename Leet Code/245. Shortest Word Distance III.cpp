class Solution 
{
public:
    int shortestWordDistance(const vector<string>& wordsDict, const string& word1, const string& word2) 
    {
        const size_t LENGTH = wordsDict.size();
        const bool isSameWord = (word1 == word2) ? true : false;
        int shortestDistance = numeric_limits<int>::max();
        int index1 = -1;
        int index2 = -1; // word1, word2의 위치
        
        for (size_t i = 0; i < LENGTH; ++i)
        {
            if (wordsDict[i] == word1)
            {
                if (isSameWord && index1 != -1) 
                {
                    // 같은 단어인 경우
                    shortestDistance = min(shortestDistance, static_cast<int>(i - index1));
                }
                index1 = i; // index1 업데이트
            }
            else if (wordsDict[i] == word2)
            {
                index2 = i; // index2 업데이트
            }

            if (!isSameWord && index1 != -1 && index2 != -1) 
            {
                shortestDistance = min(shortestDistance, abs(index1 - index2));
            }
        }

        return shortestDistance;
    }
};

// https://leetcode.com/problems/shortest-word-distance-iii/description/

/*
### 문제 번역: **가장 짧은 단어 거리 III**

**문제 설명**  
문자열 배열 `wordsDict`와 배열 내에 이미 존재하는 두 개의 문자열 `word1`과 `word2`가 주어집니다.  
이 두 단어가 배열에서 나타나는 위치 사이의 가장 짧은 거리를 반환하세요.

**특이 사항**  
- `word1`과 `word2`는 같은 단어일 수 있습니다.
- 입력값으로 주어지는 단어들은 반드시 배열 안에 존재하는 두 개의 서로 다른 단어입니다.

---

### 예제

#### 예제 1  
**입력**:
```plaintext
wordsDict = ["practice", "makes", "perfect", "coding", "makes"]
word1 = "makes"
word2 = "coding"
```

**출력**:
```plaintext
1
```

**설명**:
- `"makes"`는 인덱스 1과 4에서 나타나며, `"coding"`은 인덱스 3에서 나타납니다.  
- 가장 짧은 거리는 \( |3 - 4| = 1 \)입니다.

---

#### 예제 2  
**입력**:
```plaintext
wordsDict = ["practice", "makes", "perfect", "coding", "makes"]
word1 = "makes"
word2 = "makes"
```

**출력**:
```plaintext
3
```

**설명**:
- `"makes"`는 인덱스 1과 4에서 나타납니다.  
- 가장 짧은 거리는 \( |4 - 1| = 3 \)입니다.

---

### 제약 조건
1. \( 1 \leq \text{wordsDict.length} \leq 10^5 \)
2. \( 1 \leq \text{wordsDict[i].length} \leq 10 \)
3. `wordsDict[i]`는 소문자로 이루어진 영어 단어입니다.
4. `word1`과 `word2`는 반드시 `wordsDict` 안에 존재합니다.
*/
