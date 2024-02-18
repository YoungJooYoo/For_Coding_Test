class Solution {
public:
    string similarRGB(const string& color) 
    {
        string result = "#"; // 결과 문자열 초기화
        
        // RGB 각각에 대해 최적의 축약형 찾기
        for (int i = 1; i < color.size(); i += 2) {
            const string bestMatch = findClosest(color.substr(i, 2));
            result += bestMatch;
        }
        
        return result;
    }
    
    // 주어진 RGB 값에 가장 가까운 축약형 찾기
    string findClosest(const string& part) {
        const int value = stoi(part, nullptr, 16); // 16진수로 변환
        int quotient = value / 17; // 축약형에 가장 가까운 값 계산
        const int remainder = value % 17;
        if (remainder > 17 / 2) quotient++; // 반올림 처리
        const int closest = quotient * 17; // 가장 가까운 축약형 값 계산
        
        // 16진수 문자열로 변환
        string hex = quotient < 10 ? to_string(quotient) : string(1, 'a' + quotient - 10);
        
        return hex + hex; // 축약형 형태로 반환
    }
};


/*
RGB 색상 "#AABBCC"는 축약형 "#ABC"로 표현될 수 있습니다.

예를 들어, "#15c"는 색상 "#1155cc"의 축약형입니다.
두 색상 "#ABCDEF"와 "#UVWXYZ" 사이의 유사성은 -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2로 계산됩니다.

"#ABCDEF" 형식을 따르는 문자열 color가 주어졌을 때, 주어진 색상과 가장 유사한 색상을 나타내는 문자열을 반환하고, 
그 색상은 축약형(즉, "#XYZ" 형태로 표현될 수 있는)이어야 합니다.

최고의 답과 같은 최고의 유사성을 가진 모든 답변이 허용됩니다.

요약
주어진 RGB 색상 문자열에 대해 가장 유사한 축약형 색상을 찾아 반환하는 문제입니다. 주어진 색상과 후보 색상의 유사성을 계산하는 공식은 주어져 있으며, 
이 유사성이 최대가 되는 축약형 색상을 찾아야 합니다.

문제풀이 방향
색상 분리: 주어진 색상 문자열에서 RGB 각각의 값을 추출합니다.

가능한 축약형 생성: 가능한 모든 축약형 색상을 생성합니다. 예를 들어, '0'부터 'f'까지 각각의 값을 두 번 반복하여 사용합니다(예: '00', '11', ..., 'ff').

유사성 계산: 생성된 축약형 색상과 주어진 색상 사이의 유사성을 위에서 제공된 공식을 사용하여 계산합니다.

최대 유사성 탐색: 모든 축약형 색상에 대해 유사성을 계산하고, 최대 유사성을 가진 색상을 찾습니다.

결과 반환: 최대 유사성을 가진 축약형 색상 문자열을 반환합니다.

이 문제를 해결하기 위해선 모든 가능한 축약형 색상을 순회하면서 각각에 대해 유사성을 계산해야 합니다. 유사성이 가장 높은 축약형 색상을 결과로 반환하면 됩니다. 이 과정에서 색상 간 유사성 계산 시 주의해야 할 점은, RGB 각각의 값에 대해 16진수로 계산해야 한다는 것입니다.

*/

// https://leetcode.com/problems/similar-rgb-color/description/

