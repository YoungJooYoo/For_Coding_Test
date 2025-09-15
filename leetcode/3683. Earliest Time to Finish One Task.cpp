class Solution
{
public:
    int earliestTime(const vector<vector<int>>& tasks) const
    {
        assert(MIN_LENGTH <= tasks.size() && tasks.size() <= MAX_LENGTH);
 
        int earliestCompletionTime = numeric_limits<int>::max();

        for (const vector<int>& task : tasks)
        {
            const int startTime = task[0];
            const int duration = task[1];
            const int completionTime = startTime + duration;
            earliestCompletionTime = min(earliestCompletionTime, completionTime);
            
            assert(task.size() == VALID_TASK_LENGTH);
            assert(MIN_TIME <= startTime && startTime <= MAX_TIME);
            assert(MIN_TIME <= duration && duration <= MAX_TIME);
        }

        assert(earliestCompletionTime != numeric_limits<int>::max());
        return earliestCompletionTime;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        VALID_TASK_LENGTH = 2,
        MIN_TIME = 1,
        MAX_TIME = 100
    };
};

// https://leetcode.com/problems/earliest-time-to-finish-one-task/description/
