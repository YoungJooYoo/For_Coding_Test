class Solution {
public:
    int dayOfYear(const string& date) 
    {
        const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        const int YEAR = stoi(date.substr(0, 4));
        const int MONTH = stoi(date.substr(5, 6));
        const int DAY = stoi(date.substr(8, 9));
        int result = DAY;
        
        for (int i = 0; i < MONTH - 1; ++i) {
            result += days[i];
        }

        // 윤달체크 year
        if ((YEAR % 400) == 0 || ((YEAR % 100) != 0 && (YEAR % 4) == 0)) {
            if (MONTH > 2) ++result;
        }

        return result;
    }
};

// https://leetcode.com/problems/day-of-the-year/description/
