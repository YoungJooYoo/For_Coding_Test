class Solution {
public:
    int countTime(const string& time) 
    {
        int h1 = -1;
        int h2 = -1;
        int m1 = -1;
        int m2 = -1;
        int res = 1;

        if (time[0] != '?') { // 0 ~ 1 = 2
            h1 = time[0] - '0';
        }
        if (time[1] != '?') { // 0 ~ 9 = 10
            h2 = time[1] - '0';
        }
        if (time[3] != '?') { // 0 ~ 5 = 6
            m1 = time[3] - '0';
        }
        if (time[4] != '?') { // 0 ~ 9 = 10
            m2 = time[4] - '0';
        }

        // hour
        if (h1 == -1 && h2 == -1)  res *= 24;
        else if (h1 == -1) res *= (h2 < 4) ? 3 : 2; // 0 1 2 or 0 1
        else if (h2 == -1) res *= (h1 < 2) ? 10 : 4;

        // min
        if (m1 == -1 && m2 == -1) res *= 60;
        else if (m1 == -1) res *= 6; // 0 ~ 5
        else if (m2 == -1) res *= 10;

        return res;
    }
};

// https://leetcode.com/problems/number-of-valid-clock-times/description/
