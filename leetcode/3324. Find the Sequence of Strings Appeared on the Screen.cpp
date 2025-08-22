class Solution
{
public:
    vector<string> stringSequence(const string& target) 
    {
        const size_t targetLength = target.size();
        vector<string> screenHistory;
        string currentScreen;

        assert(MIN_TARGET_LENGTH <= targetLength && targetLength <= MAX_TARGET_LENGTH);
        for (const char targetChar : target)
        {
            assert(islower(targetChar));
            currentScreen.push_back('a');
            screenHistory.push_back(currentScreen);
            while (currentScreen.back() != targetChar)
            {
                const int nextCharOffset = (currentScreen.back() - 'a' + 1);
                currentScreen.back() = static_cast<char>((nextCharOffset % ALPHABET_LENGTH) + 'a');
                screenHistory.push_back(currentScreen);
            }
        }

        assert(screenHistory.back() == target && currentScreen == target);
        return screenHistory;
    }

private:
    enum
    {
        MIN_TARGET_LENGTH = 1,
        MAX_TARGET_LENGTH = 400,
        ALPHABET_LENGTH = 26
    };
};



// https://leetcode.com/problems/find-the-sequence-of-strings-appeared-on-the-screen/description/

/*



## 3324. 화면에 나타난 문자열의 순서 찾기

**난이도:** Medium

당신에게 문자열 `target`이 주어집니다.

앨리스는 특별한 키보드를 사용해 `target`을 타이핑하려 합니다. 이 키보드에는 단 두 개의 키만 있습니다:

* **키 1**: 화면의 문자열 끝에 문자 `"a"`를 추가한다.
* **키 2**: 화면의 문자열의 마지막 문자를 알파벳의 다음 문자로 바꾼다.
  예: `"c"` → `"d"`, `"z"` → `"a"`

초기 화면은 빈 문자열 `""`입니다. 따라서 시작 시에는 키 1만 눌러야 합니다.

앨리스가 `target`을 타이핑하는 동안, **최소한의 키 입력**으로 화면에 나타나는 **모든 문자열을 순서대로** 반환하세요.

---

### 예제 1

**입력:**
`target = "abc"`

**출력:**
`["a","aa","ab","aba","abb","abc"]`

**설명:**
앨리스의 키 입력 과정은 다음과 같습니다.

1. 키 1 → `"a"`
2. 키 1 → `"aa"`
3. 키 2 → `"ab"`
4. 키 1 → `"aba"`
5. 키 2 → `"abb"`
6. 키 2 → `"abc"`

---

### 예제 2

**입력:**
`target = "he"`

**출력:**
`["a","b","c","d","e","f","g","h","ha","hb","hc","hd","he"]`

---

### 제약 조건

* `1 <= target.length <= 400`
* `target`은 소문자 영어 알파벳으로만 이루어져 있다.

---

### 힌트

1. 먼저 키 1로 `'a'`를 붙인다.
2. 그 뒤 키 2를 여러 번 눌러 원하는 문자로 만든다.

---


*/
