class Solution {
public:
    int numberOfDays(const int year, const int month) 
    {
        const int month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int days = month_days[month - 1];

        if (month == 2 && 
            (year % 4 == 0 && year % 100 != 0) ||
            year % 400 == 0) {
                return days + 1;
            }
        
        return days;
    }

private:
    enum {
            JAN = 31, 
            FEB = 28, 
            MAR = 31, 
            APR = 30, 
            MAY = 31, 
            JUN = 30, 
            JUL = 31, 
            AUG = 31, 
            SEP = 30, 
            OCT = 31, 
            NOV = 30, 
            DEC = 31
        };
};

// https://leetcode.com/problems/number-of-days-in-a-month/description/
