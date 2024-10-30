class Solution 
{
public:
    double averageWaitingTime(const vector<vector<int>>& customers) 
    {
        const size_t LENGTH = customers.size();
        long long totalWaitingTime = 0;
        int currentTime = 0;

        for (const auto& customer : customers)
        {
            const int arrival = customer[0];
            const int time = customer[1];

            if (currentTime < arrival) 
            {
                currentTime = arrival;
            }

            currentTime += time;
            totalWaitingTime += (currentTime - arrival);
        }

        return static_cast<double>(totalWaitingTime) / LENGTH;
    }
};

// https://leetcode.com/problems/average-waiting-time/description/
