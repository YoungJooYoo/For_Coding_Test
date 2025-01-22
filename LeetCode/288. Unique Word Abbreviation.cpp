class ValidWordAbbr 
{
public:
    ValidWordAbbr(const vector<string>& dictionary) 
    {
        assert(dictionary.size() <= MAX_DICTIONARY_SIZE);

        for (const auto& word : dictionary)
        {
            const string abbreviation = generateAbbreviation(word);
            abbreviationToWordsMap[abbreviation].insert(word);
        }
    }
    
    bool isUnique(const string& word) 
    {
        assert(word.size() <= MAX_WORD_LENGTH);

        if (word.size() <= 2)
        {
            return true;
        }

        const string abbreviation = generateAbbreviation(word);
        const unordered_set<string>& wordsWithSameAbbreviation = abbreviationToWordsMap[abbreviation];
        
        return (wordsWithSameAbbreviation.empty() || 
               (wordsWithSameAbbreviation.size() == 1 && wordsWithSameAbbreviation.count(word))) ? true : false;
    }

private:
    string generateAbbreviation(const string& word) const
    {
        const size_t length = word.size();
        assert(length <= MAX_WORD_LENGTH);

        if (length <= 2)
        {
            return word;
        }

        const size_t middleCharCount = length - 2;
        return word[0] + to_string(middleCharCount) + word[length - 1];
    }

private:
    unordered_map<string, unordered_set<string>> abbreviationToWordsMap; // 축약어 -> 단어 집합 매핑

    enum 
    {
        MAX_DICTIONARY_SIZE = 30000, // dictionary의 최대 크기
        MAX_WORD_LENGTH = 20         // 단어의 최대 길이
    };
};

// https://leetcode.com/problems/unique-word-abbreviation/description/

/*

### 288. 고유 단어 축약 (Unique Word Abbreviation)

#### 문제 설명
단어의 축약어는 단어의 첫 글자, 첫 글자와 마지막 글자 사이의 문자 개수, 마지막 글자를 연결하여 생성됩니다. 만약 단어가 두 글자라면, 그 자체가 축약어가 됩니다.

**예시:**
- `dog` → `d1g` (첫 글자 `d`와 마지막 글자 `g` 사이에 한 글자가 있음)
- `internationalization` → `i18n` (첫 글자 `i`와 마지막 글자 `n` 사이에 18개의 글자가 있음)
- `it` → `it` (두 글자짜리 단어는 본인이 축약어가 됨)

`ValidWordAbbr` 클래스를 구현하세요:

- **`ValidWordAbbr(String[] dictionary)`**  
  주어진 단어 목록으로 객체를 초기화합니다.
  
- **`boolean isUnique(string word)`**  
  주어진 조건 중 하나라도 충족되면 `true`를 반환하고, 그렇지 않으면 `false`를 반환합니다:
  1. 사전에 있는 어떤 단어도 `word`의 축약어와 동일하지 않을 때.
  2. 사전에 있는 모든 단어 중 `word`와 동일한 축약어를 가진 단어가 있다면, 그 단어가 `word`와 동일할 때.

---

#### 예제

**입력:**
```plaintext
["ValidWordAbbr", "isUnique", "isUnique", "isUnique", "isUnique", "isUnique"]
[[["deer", "door", "cake", "card"]], ["dear"], ["cart"], ["cane"], ["make"], ["cake"]]
```

**출력:**
```plaintext
[null, false, true, false, true, true]
```

**설명:**
```plaintext
ValidWordAbbr validWordAbbr = new ValidWordAbbr(["deer", "door", "cake", "card"]);

validWordAbbr.isUnique("dear"); 
// false: 사전의 "deer"와 주어진 단어 "dear"는 같은 축약어 "d2r"를 가지지만 서로 다른 단어입니다.

validWordAbbr.isUnique("cart"); 
// true: 사전의 어떤 단어도 "cart"와 동일한 축약어 "c2t"를 가지지 않습니다.

validWordAbbr.isUnique("cane"); 
// false: 사전의 "cake"와 주어진 단어 "cane"는 같은 축약어 "c2e"를 가지지만 서로 다른 단어입니다.

validWordAbbr.isUnique("make"); 
// true: 사전의 어떤 단어도 "make"와 동일한 축약어 "m2e"를 가지지 않습니다.

validWordAbbr.isUnique("cake"); 
// true: "cake"는 이미 사전에 존재하며, 동일한 축약어 "c2e"를 가지는 다른 단어는 없습니다.
```

---

#### 제약 조건
- `1 <= dictionary.length <= 30,000`
- `1 <= dictionary[i].length <= 20`
- `dictionary[i]`는 소문자로 이루어진 영어 단어입니다.
- `1 <= word.length <= 20`
- `word`는 소문자로 이루어진 영어 단어입니다.
- `isUnique` 함수는 최대 5,000번 호출됩니다.
*/


/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
