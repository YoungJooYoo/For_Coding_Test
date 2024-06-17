class Solution 
{
public:
    int countCompleteDayPairs(const vector<int>& hours) 
    {
        const size_t LENGTH = hours.size();
        int result = 0;

        for (size_t i = 0; i < LENGTH; ++i)
        {
            for (size_t j = i + 1; j < LENGTH; ++j)
            {
                if ((hours[i] + hours[j]) % 24 == 0) ++result;
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/count-pairs-that-form-a-complete-day-i/description/
