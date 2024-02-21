class Solution {
public:
    string nextClosestTime(const string& time) 
    {
        set<int> digits;
        for (const char c : time) {
            if (c != ':') {
                digits.insert(c - '0');
            }
        }

        const int currentTime = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
        int closestTime = 24 * 60; // 최대 시간 + 1
        int answerTime = currentTime;
        
        const vector<int> digitsVec(digits.begin(), digits.end());
        for (const int h1 : digitsVec) {
            for (const int h2 : digitsVec) {
                for (const int m1 : digitsVec) {
                    for (const int m2 : digitsVec) {
                        const int hours = h1 * 10 + h2;
                        const int minutes = m1 * 10 + m2;
                        if (hours < 24 && minutes < 60) {
                            const int newTime = hours * 60 + minutes;
                            int diff = newTime - currentTime;
                            if (diff <= 0) diff += 24 * 60; // 다음 날로 넘어가는 경우
                            if (diff < closestTime) {
                                closestTime = diff;
                                answerTime = newTime;
                            }
                        }
                    }
                }
            }
        }

        char buffer[6];
        sprintf(buffer, "%02d:%02d", answerTime / 60, answerTime % 60);
        return string(buffer);
    }
};

// https://leetcode.com/problems/next-closest-time/description/
