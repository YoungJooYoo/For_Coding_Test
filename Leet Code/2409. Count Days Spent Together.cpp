class Solution {
public:
    int convert_into_day(const string& days)
    {
        const int MONTH = stoi(string(1, days[0]) + days[1]);
        const int DAY = stoi(string(1, days[3]) + days[4]);
        int total_days = 0;

        for (size_t i = 1; i < MONTH; ++i) {
            total_days += month[i];
        }
        total_days += DAY;

        return total_days;
    }

    int countDaysTogether(const string& arriveAlice, const string& leaveAlice, const string& arriveBob, const string& leaveBob) 
    {
        const int alice_arrive = convert_into_day(arriveAlice);
        const int alice_leave = convert_into_day(leaveAlice);
        const int bob_arrive = convert_into_day(arriveBob);
        const int bob_leave = convert_into_day(leaveBob);

        const int arrive = max(alice_arrive,  bob_arrive);
        const int leave = min(alice_leave, bob_leave);

        return arrive > leave ? 0 : leave - arrive + 1;
    }

private:
    const int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
};

// https://leetcode.com/problems/count-days-spent-together/description/
