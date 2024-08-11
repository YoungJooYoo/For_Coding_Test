class Solution 
{
public:
    vector<vector<int>> largeGroupPositions(const string& s) 
    {
        const size_t LENGTH = s.size();
        vector<vector<int>> result;
        size_t i = 0;
        size_t j = 0;

        while (i < LENGTH) 
        {
            j = i;
            // Find the end of the current group of characters
            while (j < LENGTH && s[j] == s[i]) 
            {
                ++j;
            }

            // If the group length is 3 or more, add it to the result
            if (j - i >= LARGE_LENGTH) 
            {
                result.push_back({static_cast<int>(i), static_cast<int>(j - 1)});
            }

            // Move i to the start of the next group
            i = j;
        }

        return result;
    }
    
private:
    enum
    {
        LARGE_LENGTH = 3
    };
};

// https://leetcode.com/problems/positions-of-large-groups/description/

/*

### 830. 큰 그룹의 위치

**난이도: 쉬움**

#### 문제 설명

소문자로 이루어진 문자열 `s`가 주어졌을 때, 이 문자열은 같은 문자로 이루어진 연속적인 그룹을 형성합니다.

예를 들어, 문자열 `s = "abbxxxxzyy"`는 `"a"`, `"bb"`, `"xxxx"`, `"z"`, `"yy"`와 같은 그룹을 가집니다.

그룹은 `[start, end]`라는 구간으로 식별되며, 여기서 `start`와 `end`는 그룹의 시작과 끝 인덱스(포함)를 나타냅니다. 위 예시에서 `"xxxx"`는 `[3, 6]` 구간을 가집니다.

그룹의 길이가 3 이상인 경우 이를 큰 그룹으로 간주합니다.

모든 큰 그룹의 구간을 시작 인덱스가 증가하는 순서로 반환하세요.

#### 예제

**예제 1**:
- **입력**: `s = "abbxxxxzzy"`
- **출력**: `[[3,6]]`
- **설명**: `"xxxx"`는 유일한 큰 그룹이며, 시작 인덱스 3과 끝 인덱스 6을 가집니다.

**예제 2**:
- **입력**: `s = "abc"`
- **출력**: `[]`
- **설명**: `"a"`, `"b"`, `"c"`는 모두 큰 그룹이 아닙니다.

**예제 3**:
- **입력**: `s = "abcdddeeeeaabbbcd"`
- **출력**: `[[3,5],[6,9],[12,14]]`
- **설명**: 큰 그룹은 `"ddd"`, `"eeee"`, `"bbb"`입니다.

#### 제약 조건
- `1 <= s.length <= 1000`
- `s`는 소문자 영어 문자로만 구성됩니다.
*/
