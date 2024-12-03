#define SPACE_CHAR (' ')
#define NULL_CHAR ('\0')

class Solution 
{
public:
    string addSpaces(const string& s, const vector<int>& spaces) 
    {
        string outString;
        size_t i = 0;
        size_t j = 0;
        const size_t SPACE_LENGTH = spaces.size();

        while (s[i] != NULL_CHAR)
        {
            if (j < SPACE_LENGTH && i == spaces[j])
            {
                outString.push_back(SPACE_CHAR);
                ++j;
            }
            outString.push_back(s[i++]);
        }

        return outString;
    }
};

// https://leetcode.com/problems/adding-spaces-to-a-string/description/?envType=daily-question&envId=2024-12-03

/*
**2109. 문자열에 공백 추가하기**  
난이도: 중간

**문제 설명**  
0-인덱스 문자열 `s`와 0-인덱스 정수 배열 `spaces`가 주어집니다. 이 배열은 원래 문자열에서 공백을 추가할 인덱스를 설명합니다. 각 공백은 주어진 인덱스의 문자 앞에 삽입됩니다.

예를 들어, `s = "EnjoyYourCoffee"`와 `spaces = [5, 9]`가 주어졌을 때, 인덱스 5와 9의 문자 앞에 공백을 삽입하면 `"Enjoy Your Coffee"`를 얻습니다.  
공백이 추가된 후 수정된 문자열을 반환하세요.

**예제 1**  
입력: `s = "LeetcodeHelpsMeLearn"`, `spaces = [8, 13, 15]`  
출력: `"Leetcode Helps Me Learn"`  
설명:  
인덱스 8, 13, 15는 각각 `"LeetcodeHelpsMeLearn"` 문자열의 밑줄 친 문자들입니다. 해당 문자 앞에 공백을 삽입합니다.

**예제 2**  
입력: `s = "icodeinpython"`, `spaces = [1, 5, 7, 9]`  
출력: `"i code in py thon"`  
설명:  
인덱스 1, 5, 7, 9는 `"icodeinpython"` 문자열의 밑줄 친 문자들입니다. 해당 문자 앞에 공백을 삽입합니다.

**예제 3**  
입력: `s = "spacing"`, `spaces = [0, 1, 2, 3, 4, 5, 6]`  
출력: `" s p a c i n g"`  
설명:  
문자열의 첫 번째 문자 앞에도 공백을 추가할 수 있습니다.

**제약 사항**  
- `1 <= s.length <= 3 * 10^5`
- `s`는 소문자와 대문자로만 구성되어 있습니다.
- `1 <= spaces.length <= 3 * 10^5`
- `0 <= spaces[i] <= s.length - 1`
- `spaces`의 모든 값은 엄격히 증가합니다.
*/
