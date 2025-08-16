class Solution
{
public:
    int earliestFinishTime(const vector<int>& landStartTime, const vector<int>& landDuration, const vector<int>& waterStartTime, const vector<int>& waterDuration) const
    {
        const size_t landLength  = landStartTime.size();
        const size_t waterLength = waterStartTime.size();

        assert(landLength  == landDuration.size());
        assert(waterLength == waterDuration.size());
        assert(MIN_LEN <= landLength  && landLength  <= MAX_LEN);
        assert(MIN_LEN <= waterLength && waterLength <= MAX_LEN);

        const int optionLandThenWater = calculateOption(landStartTime, landDuration, waterStartTime, waterDuration); // 육지 먼저 → 물
        const int optionWaterThenLand = calculateOption(waterStartTime, waterDuration, landStartTime, landDuration); // 물 먼저 → 육지
        const int answer = min(optionLandThenWater, optionWaterThenLand);

        assert(answer != numeric_limits<int>::max());
        return answer;
    }

private:
    int calculateOption(const vector<int>& firstStartTime, const vector<int>& firstDuration, const vector<int>& secondStartTime, const vector<int>& secondDuration) const
    {
        
        const int earliestFirstFinish = getEarliestFinishTime(firstStartTime, firstDuration); // 첫 번째 작업의 가장 빠른 완료 시간 계산
        return getBestFinishTimeAfter(earliestFirstFinish, secondStartTime, secondDuration); // 두 번째 작업의 최적 완료 시간 계산
    }
    
    int getEarliestFinishTime(const vector<int>& startTimes, const vector<int>& durations) const
    {
        int earliest = numeric_limits<int>::max();

        for (size_t i = 0; i < startTimes.size(); ++i)
        {
            assert(MIN_TIME <= startTimes[i] && startTimes[i] <= MAX_TIME);
            assert(MIN_TIME <= durations[i] && durations[i] <= MAX_TIME);
            earliest = min(earliest, startTimes[i] + durations[i]);
        }

        return earliest;
    }
    
    int getBestFinishTimeAfter(int earliestStart, const vector<int>& startTimes, const vector<int>& durations) const
    {
        int bestFinish = numeric_limits<int>::max();

        for (size_t i = 0; i < startTimes.size(); ++i)
        {
            assert(MIN_TIME <= startTimes[i] && startTimes[i] <= MAX_TIME);
            assert(MIN_TIME <= durations[i] && durations[i] <= MAX_TIME);
            const int actualStart = max(earliestStart, startTimes[i]);
            bestFinish = min(bestFinish, actualStart + durations[i]);
        }
        
        return bestFinish;
    }

    enum
    {
        MIN_LEN  = 1,
        MAX_LEN  = 5 * 10000,
        MIN_TIME = 1,
        MAX_TIME = 100000
    };
};

// https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/
