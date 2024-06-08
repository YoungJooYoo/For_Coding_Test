class Solution 
{
public:
    bool isVowel(const char ch)
    {
        switch (tolower(ch))
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
    }

    string toGoatLatin(const string& sentence) 
    {
        istringstream iss(sentence);
        vector<string> words;
        string temp;
        string result;
        const string postfix = "ma";
        string tail = "a";

        while (iss >> temp)
        {
            if (isVowel(temp.front()) == true)
            {
                temp += postfix;

            }
            else 
            {
                temp = temp.substr(1) + temp.front() + postfix;
            }
            temp += tail;
            tail += "a";
            words.push_back(temp);
        }

        result += words[0];
        for (size_t i = 1; i < words.size(); ++i)
        {
            result += " " + words[i];
        }

        return result;
    }
};

// https://leetcode.com/problems/goat-latin/

/*
### 824. 염소 라틴어
**난이도: 쉬움**

문제가 있는 문장은 단어들이 공백으로 구분되어 있습니다. 각 단어는 소문자와 대문자만으로 이루어져 있습니다.

문장을 "염소 라틴어"로 변환하려고 합니다 (이것은 피그 라틴어와 유사한 가상의 언어입니다). 염소 라틴어의 규칙은 다음과 같습니다:

1. 단어가 모음('a', 'e', 'i', 'o', 'u')으로 시작하면, 단어 끝에 "ma"를 추가합니다.
   - 예를 들어, "apple"이라는 단어는 "applema"가 됩니다.
2. 단어가 자음(즉, 모음이 아닌 문자)으로 시작하면, 첫 글자를 제거하고 단어 끝에 붙인 후, "ma"를 추가합니다.
   - 예를 들어, "goat"라는 단어는 "oatgma"가 됩니다.
3. 각 단어에 대해, 문장에서의 단어 인덱스에 따라 끝에 'a' 문자를 하나씩 추가합니다. 인덱스는 1부터 시작합니다.
   - 예를 들어, 첫 번째 단어는 끝에 "a"가 추가되고, 두 번째 단어는 끝에 "aa"가 추가되며, 이런 식으로 계속됩니다.

문장을 염소 라틴어로 변환한 최종 결과를 반환하세요.

### 예제 1

- 입력: `sentence = "I speak Goat Latin"`
- 출력: `"Imaa peaksmaaa oatGmaaaa atinLmaaaaa"`

### 예제 2

- 입력: `sentence = "The quick brown fox jumped over the lazy dog"`
- 출력: `"heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"`

### 제약 조건

- `sentence.length`는 1 이상 150 이하입니다.
- `sentence`는 영어 문자와 공백으로 구성됩니다.
- 문장에는 앞뒤에 공백이 없으며, 모든 단어는 단일 공백으로 구분됩니다.
*/
