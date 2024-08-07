class Solution {
public:
    int minimumPushes(const string& word) 
    {
        vector<int> freq(ALPHABET_LENGTH, 0);
        int result =  0;

        for (const auto& ch : word)
        {
            ++freq[ch - 'a'];
        }

        sort(freq.begin(), freq.end(), greater<int>());

        for (size_t i = 0; i < ALPHABET_LENGTH; ++i)
        {
            result += ((i /  LENGTH) + 1) * freq[i];
        }

        return result;
    }

private:
    enum
    {
        ALPHABET_LENGTH = 26,
        LENGTH = 8,
    };
};

// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2024-08-06

/*

### 문제: 최소 횟수로 단어 입력하기 II

전화 키패드에는 소문자 영어 알파벳이 각각 다른 집합으로 매핑된 키가 있습니다. 이 키를 눌러 단어를 입력할 수 있습니다. 예를 들어, 키 2는 ["a", "b", "c"]로 매핑되며, "a"를 입력하려면 한 번, "b"를 입력하려면 두 번, "c"를 입력하려면 세 번 눌러야 합니다.

키 2부터 9까지의 키는 서로 다른 문자 집합으로 재매핑하는 것이 허용됩니다. 각 문자는 정확히 하나의 키에 매핑되어야 하지만, 키는 임의의 개수의 문자로 매핑될 수 있습니다. 문자열 `word`를 입력하기 위해 키를 누르는 최소 횟수를 구하세요.

키패드에서 문자와 키의 예시 매핑은 아래 그림과 같습니다. 1, *, #, 0은 어떤 문자에도 매핑되지 않습니다.

#### 예시 1:

- 입력: `word = "abcde"`
- 출력: `5`
- 설명: 예시 매핑은 다음과 같습니다:
  - "a" -> 키 2를 한 번 누름
  - "b" -> 키 3을 한 번 누름
  - "c" -> 키 4를 한 번 누름
  - "d" -> 키 5를 한 번 누름
  - "e" -> 키 6을 한 번 누름
  - 총 비용은 1 + 1 + 1 + 1 + 1 = 5.
  - 이보다 낮은 비용을 제공하는 다른 매핑은 없습니다.

#### 예시 2:

- 입력: `word = "xyzxyzxyzxyz"`
- 출력: `12`
- 설명: 예시 매핑은 다음과 같습니다:
  - "x" -> 키 2를 한 번 누름
  - "y" -> 키 3을 한 번 누름
  - "z" -> 키 4를 한 번 누름
  - 총 비용은 1 * 4 + 1 * 4 + 1 * 4 = 12
  - 이보다 낮은 비용을 제공하는 다른 매핑은 없습니다.

#### 예시 3:

- 입력: `word = "aabbccddeeffgghhiiiiii"`
- 출력: `24`
- 설명: 예시 매핑은 다음과 같습니다:
  - "a" -> 키 2를 한 번 누름
  - "b" -> 키 3을 한 번 누름
  - "c" -> 키 4를 한 번 누름
  - "d" -> 키 5를 한 번 누름
  - "e" -> 키 6을 한 번 누름
  - "f" -> 키 7을 한 번 누름
  - "g" -> 키 8을 한 번 누름
  - "h" -> 키 9를 두 번 누름
  - "i" -> 키 9를 한 번 누름
  - 총 비용은 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 2 * 2 + 6 * 1 = 24.
  - 이보다 낮은 비용을 제공하는 다른 매핑은 없습니다.
*/
