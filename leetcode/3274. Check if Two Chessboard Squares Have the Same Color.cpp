class Solution 
{
public:
    bool checkTwoChessboards(const string& coordinate1, const string& coordinate2) 
    {
        const bool bCoordinate1IsBlack = isBlackSquare(coordinate1);
        const bool bCoordinate2IsBlack = isBlackSquare(coordinate2);

        return (bCoordinate1IsBlack == bCoordinate2IsBlack) ? true : false;
    }

private:
    bool isBlackSquare(const string& coordinate)
    {
        const size_t i = coordinate[0] - 'a';
        const size_t j = coordinate[1] - '1';

        return ((i + j) % 2 == 1) ? true : false;
    }
};

// https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color/description/

/*

3274. 두 체스판 칸이 같은 색인지 확인하기
두 문자열 coordinate1과 coordinate2가 주어지며, 이는 8 x 8 체스판의 한 칸을 나타냅니다.

아래는 참조용으로 제공된 체스판입니다.

![체스판 이미지]

두 칸이 같은 색이면 true를 반환하고, 그렇지 않으면 false를 반환하세요.

좌표는 항상 유효한 체스판 칸을 나타냅니다. 좌표는 항상 열(문자)을 먼저 표시하고, 행(숫자)을 두 번째로 표시합니다.

예제 1:
입력: coordinate1 = "a1", coordinate2 = "c3"
출력: true
설명: 두 칸 모두 검정색입니다.
예제 2:
입력: coordinate1 = "a1", coordinate2 = "h3"
출력: false
설명: "a1" 칸은 검정색이고, "h3" 칸은 흰색입니다.
제한 조건:
coordinate1.length == coordinate2.length == 2
'a' <= coordinate1[0], coordinate2[0] <= 'h'
'1' <= coordinate1[1], coordinate2[1] <= '8'

*/
