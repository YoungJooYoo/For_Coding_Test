class Solution 
{
public:
    string dayOfTheWeek(int day, int month, int year) 
    {
        const int dayOfWeek = calculateDayOfWeek(day, month, year);
        return DAYS[dayOfWeek];
    }

private:
    const vector<string> DAYS = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    int calculateDayOfWeek(int day, int month, int year) 
    {
        const static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        year -= month < 3;
        return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
    }
};


/*
이 문제에서는 주어진 날짜에 해당하는 요일을 반환해야 합니다. 입력은 날짜를 나타내는 세 개의 정수로 주어집니다. 세 개의 정수는 각각 일(day), 월(month), 년(year)을 나타냅니다.

요일은 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"} 중 하나로 반환되어야 합니다.

예를 들어,

입력: day = 31, month = 8, year = 2019
출력: "Saturday"
입력: day = 18, month = 7, year = 1999
출력: "Sunday"
입력: day = 15, month = 8, year = 1993
출력: "Sunday"

위와 같이 날짜가 주어지면 해당 날짜의 요일을 반환해야 합니다.

제약 조건은 다음과 같습니다:
- 주어진 날짜는 1971년부터 2100년 사이의 유효한 날짜입니다.

*/

// https://leetcode.com/problems/day-of-the-week/description/
