class Solution 
{
public:
    bool canChange(const string& start, const string& target) 
    {
        if (!isValidInput(start, target)) 
        {
            return false;
        }

        vector<pair<char, int>> startPattern;
        vector<pair<char, int>> targetPattern;

        // 'R'과 'L'의 패턴과 위치를 추출합니다.
        for (size_t i = 0; i < start.size(); ++i) 
        {
            if (start[i] == 'R' || start[i] == 'L') 
            {
                startPattern.emplace_back(start[i], i);
            }
        }

        for (size_t i = 0; i < target.size(); ++i) 
        {
            if (target[i] == 'R' || target[i] == 'L') 
            {
                targetPattern.emplace_back(target[i], i);
            }
        }

        // 패턴이 일치하지 않으면 false를 반환합니다.
        if (startPattern.size() != targetPattern.size()) 
        {
            return false;
        }

        for (size_t i = 0; i < startPattern.size(); ++i) 
        {
            // 각 위치의 문자와 상대적 위치를 비교합니다.
            if (startPattern[i].first != targetPattern[i].first) 
            {
                return false;
            }

            const char ch = startPattern[i].first;
            const int startIndex = startPattern[i].second;
            const int targetIndex = targetPattern[i].second;

            // 'R'은 오른쪽으로만 이동할 수 있습니다.
            if (ch == 'R' && startIndex > targetIndex) 
            {
                return false;
            }

            // 'L'은 왼쪽으로만 이동할 수 있습니다.
            if (ch == 'L' && startIndex < targetIndex) 
            {
                return false;
            }
        }

        return true;
    }

private:
    bool isValidInput(const string& start, const string& target)
    {
        int countR = 0;
        int countL = 0;

        for (const auto ch : start)
        {
            if (ch == 'R') 
            {
                ++countR;
            }
            else if (ch == 'L') 
            {
                ++countL;
            }
        }

        for (const auto ch : target)
        {
            if (ch == 'R') 
            {
                --countR;
            }
            else if (ch == 'L') 
            {
                --countL;
            }
        }

        // 'R'과 'L'의 개수가 같아야 합니다.
        return (countR == 0 && countL == 0);
    }
};

// https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/?envType=daily-question&envId=2024-12-05

/*
**2337. 문자열 얻기 위한 말 이동**  
난이도: 중간

**문제 설명**  
두 문자열 `start`와 `target`이 주어집니다. 두 문자열의 길이는 `n`이며, 각각 'L', 'R', 그리고 '_' 문자로만 구성됩니다:

- 문자 'L'과 'R'은 각각 왼쪽과 오른쪽으로만 이동할 수 있는 말입니다.
  - 'L'은 자신의 왼쪽에 빈 공간('_')이 있을 때만 왼쪽으로 이동할 수 있습니다.
  - 'R'은 자신의 오른쪽에 빈 공간('_')이 있을 때만 오른쪽으로 이동할 수 있습니다.
- 문자 '_'는 빈 공간을 나타내며, 이 공간은 'L' 또는 'R'이 차지할 수 있습니다.

`start` 문자열에 있는 말을 몇 번이든 이동하여 `target` 문자열을 얻는 것이 가능한지 확인하세요. 가능하다면 `true`를, 불가능하다면 `false`를 반환하세요.

**예제**  

- 예제 1:
  - 입력: `start = "_L__R__R_"`, `target = "L______RR"`
  - 출력: `true`
  - 설명: 다음과 같이 말들을 이동하여 `target` 문자열을 얻을 수 있습니다:
    - 첫 번째 'L'을 왼쪽으로 한 칸 이동: `start`는 `"L___R__R_"`가 됩니다.
    - 마지막 'R'을 오른쪽으로 한 칸 이동: `start`는 `"L___R___R"`가 됩니다.
    - 두 번째 'R'을 오른쪽으로 세 칸 이동: `start`는 `"L______RR"`이 됩니다.
    - 따라서, `target` 문자열을 얻을 수 있으므로 `true`를 반환합니다.

- 예제 2:
  - 입력: `start = "R_L_"`, `target = "__LR"`
  - 출력: `false`
  - 설명: 문자열 `start`에서 'R'을 오른쪽으로 한 칸 이동하여 `"_RL_"`를 얻을 수 있습니다. 이후에는 더 이상 말을 움직일 수 없으므로 `target`을 얻는 것은 불가능합니다.

- 예제 3:
  - 입력: `start = "_R"`, `target = "R_"`
  - 출력: `false`
  - 설명: 문자열 `start`에서 'R'은 오른쪽으로만 이동할 수 있으므로 `target` 문자열을 얻는 것은 불가능합니다.

**제약 사항**  
- `n == start.length == target.length`
- `1 <= n <= 10^5`
- `start`와 `target`은 'L', 'R', 그리고 '_' 문자로만 구성됩니다.

*/

