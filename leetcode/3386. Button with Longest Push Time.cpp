class Solution 
{
public:
    int buttonWithLongestTime(const vector<vector<int>>& events) 
    {
        const size_t LENGTH = events.size();
        int longestTime = events[0][1];
        int longestTimeButton = events[0][0];
        
        for (size_t i = 1; i < LENGTH; ++i)
        {
            const int previousTime = events[i - 1][1];
            const int currentTime = events[i][1];
            const int timeDifference = currentTime - previousTime;
            
            if (longestTime < timeDifference || (timeDifference == longestTime && events[i][0] < longestTimeButton))
            {
               longestTime = currentTime - previousTime;
               longestTimeButton = events[i][0];
            }
        }

        return longestTimeButton;
    }
};

// https://leetcode.com/problems/button-with-longest-push-time/

/*
문제 번역: 가장 오래 눌린 버튼 찾기
문제 설명
2D 배열 events가 주어지며, 이는 한 아이가 키보드의 버튼을 누른 일련의 이벤트를 나타냅니다.
각 events[i] = [indexi, timei]는 인덱스 indexi에 있는 버튼이 시간 timei에 눌렸음을 의미합니다.

배열은 시간 순으로 오름차순으로 정렬되어 있습니다.
버튼을 누르는 데 걸린 시간은 연속된 버튼 누름 사이의 시간 차이입니다. 첫 번째 버튼은 눌린 시간이 그 자체로 누른 시간입니다.
목표
가장 오래 눌린 버튼의 인덱스를 반환하세요. 만약 여러 버튼이 같은 시간 동안 눌렸다면, 인덱스가 가장 작은 버튼을 반환하세요.

*/
