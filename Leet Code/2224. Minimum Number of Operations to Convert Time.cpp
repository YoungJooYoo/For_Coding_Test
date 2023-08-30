class Solution {
public:
    int convertTime(string current, string correct) 
    {
        int count = 0;
        string temp;
        temp.push_back(current[0]);
        temp.push_back(current[1]);
        int curr_hour = stoi(temp);

        temp.clear();
        temp.push_back(current[3]);
        temp.push_back(current[4]);
        int curr_min = stoi(temp);

        temp.clear();
        temp.push_back(correct[0]);
        temp.push_back(correct[1]);
        int corr_hour = stoi(temp);

        temp.clear();
        temp.push_back(correct[3]);
        temp.push_back(correct[4]);
        int corr_min = stoi(temp);

        int correct_min = HOUR * corr_hour + corr_min;
        int current_min = HOUR * curr_hour + curr_min;
        
        while (correct_min > current_min) {
            if ((correct_min - current_min) >= HOUR) {
                current_min = current_min + HOUR;
                ++count;
            }
            else if ((correct_min - current_min) >= 15) {
                current_min = current_min + 15;
                ++count;
            }
            else if ((correct_min - current_min) >= 5) {
                current_min = current_min + 5;
                ++count;
            }
            else {
                count += (correct_min - current_min);
                current_min = current_min + (correct_min - current_min);
            }
        }

        return count;
    }

private:
    enum { HOUR = 60 };
};

// https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/
