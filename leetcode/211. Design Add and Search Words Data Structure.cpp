class WordDictionary
{
public:
    WordDictionary()
    {

    }

    void addWord(const string& word)
    {
        assert(MIN_WORD_LENGTH <= word.size() && word.size() <= MAX_WORD_LENGTH);
        for (const char ch : word)
        {
            assert('a' <= ch && ch <= 'z');
        }
        mWords.push_back(word);
    }

    bool search(const string& word) const
    {
        assert(MIN_WORD_LENGTH <= word.size() && word.size() <= MAX_WORD_LENGTH);
        int dotCount = 0;
        for (const char ch : word)
        {
            if (ch == '.') ++dotCount;
            else assert('a' <= ch && ch <= 'z');
            assert(dotCount <= MAX_DOT_COUNT);
        }

        // logic start
        for (const string& candidate : mWords)
        {
            if (candidate.size() != word.size())
            {
                continue;
            }
            const size_t LENGTH = word.size();
            bool bIsMatch = true;
            for (size_t i = 0; i < LENGTH; ++i)
            {
                if (word[i] == '.')
                {
                    continue;
                }
                if (candidate[i] != word[i])
                {
                    bIsMatch = false;
                    break;
                }
            }
            if (bIsMatch == true)
            {
                return true;
            }
        }

        return false;
    }

private:
    vector<string> mWords;

    enum
    {
        MIN_WORD_LENGTH = 1,
        MAX_WORD_LENGTH = 25,
        MAX_DOT_COUNT   = 2
    };
};

/**
// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

## 211. 단어 추가 및 검색 데이터 구조 설계

새로운 단어를 추가하고, 이전에 추가된 단어들 중에서 주어진 문자열과 일치하는 단어가 있는지 찾는 데이터 구조를 설계하세요.

`WordDictionary` 클래스를 구현하세요:

*   `WordDictionary()`: 객체를 초기화합니다.
*   `void addWord(word)`: `word`를 데이터 구조에 추가합니다. 이 단어는 나중에 검색될 수 있습니다.
*   `bool search(word)`: 데이터 구조에 `word`와 일치하는 문자열이 있으면 `true`를, 그렇지 않으면 `false`를 반환합니다. `word`는 임의의 문자 하나와 일치할 수 있는 점(`.`)을 포함할 수 있습니다.

---

**예시:**

**입력:**
```
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
```

**출력:**
```
[null,null,null,null,false,true,true,true]
```

**설명:**
```cpp
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // False 반환
wordDictionary.search("bad"); // True 반환
wordDictionary.search(".ad"); // True 반환 ('.ad'는 "bad", "dad", "mad" 중 하나와 일치)
wordDictionary.search("b.."); // True 반환 ('b..'는 "bad"와 일치)
```

---

**제약 조건:**

*   `1 <= word.length <= 25`
*   `addWord`에 사용되는 `word`는 소문자 영어 알파벳으로 구성됩니다.
*   `search`에 사용되는 `word`는 `.` 또는 소문자 영어 알파벳으로 구성됩니다.
*   `search` 쿼리에서 `word`는 최대 2개의 점(`.`)을 포함할 수 있습니다.
*   `addWord`와 `search` 호출은 최대 10^4번 이루어집니다.
 */
