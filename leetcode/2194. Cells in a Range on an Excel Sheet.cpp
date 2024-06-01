class Solution 
{
public:
    vector<string> cellsInRange(const string& s) 
    {
        vector<string> result;
        const size_t LENGTH = s.size();

        const int START_ROW_IDX = s[1] - '0';
        const int END_ROW_IDX = s[4] - '0';

        const char START_COL = s[0];
        const char END_COL = s[3];

        for (char col = START_COL; col <= END_COL; ++col)
        {
            for (int row = START_ROW_IDX; row <= END_ROW_IDX; ++row)
            {
                result.push_back(string(1, col) + to_string(row));
            }
        }
  
        return result;
    }
};

// https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/description/

/*
문제 설명
엑셀 시트의 셀 (r, c)는 문자열 "<col><row>" 형식으로 표현됩니다. 여기서 <col>은 열 번호를 나타내며, 알파벳 문자로 표시됩니다. 예를 들어, 1번째 열은 'A', 2번째 열은 'B', 3번째 열은 'C' 등으로 표시됩니다. <row>는 행 번호를 나타내며, 정수로 표시됩니다.

문자열 s가 "<col1><row1>:<col2><row2>" 형식으로 주어집니다. 여기서 <col1>은 열 c1을, <row1>은 행 r1을, <col2>는 열 c2를, <row2>는 행 r2를 나타냅니다. r1 <= r2이고 c1 <= c2가 항상 성립합니다.

r1 <= x <= r2 및 c1 <= y <= c2를 만족하는 셀 (x, y)의 목록을 반환하세요. 셀은 주어진 형식대로 문자열로 표현되며, 열과 행의 오름차순으로 정렬되어야 합니다.

예제
예제 1:

입력: s = "K1:L2"
출력: ["K1", "K2", "L1", "L2"]
설명: 아래 다이어그램은 목록에 있어야 하는 셀을 보여줍니다. 빨간 화살표는 셀이 표시되는 순서를 나타냅니다.
예제 2:

입력: s = "A1:F1"
출력: ["A1", "B1", "C1", "D1", "E1", "F1"]
설명: 아래 다이어그램은 목록에 있어야 하는 셀을 보여줍니다. 빨간 화살표는 셀이 표시되는 순서를 나타냅니다.
제약 조건
s.length == 5
'A' <= s[0] <= s[3] <= 'Z'
'1' <= s[1] <= s[4] <= '9'
s는 대문자 영어 문자, 숫자 및 ':'로 구성됩니다.
풀이 방향
주어진 문자열 s를 파싱하여 시작 열(col1), 시작 행(row1), 종료 열(col2), 종료 행(row2)을 추출합니다.
열은 문자 범위로, 행은 숫자 범위로 반복하여 필요한 셀들을 생성합니다.
생성된 셀들을 문자열 목록에 추가합니다.
최종 목록을 반환합니다.

*/
