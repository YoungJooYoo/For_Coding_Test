class Solution 
{
public:
    int maxScoreSightseeingPair(const vector<int>& values) 
    {
        const int LENGTH = values.size();
        int maxScore = numeric_limits<int>::min();
        int maxValPlusIndex = values[0]; // maxScorePlusI = max values[i] + i

        for (int currentIndex = 1; currentIndex < LENGTH ; ++currentIndex) 
        { 
            const int currentValMinusIndex = values[currentIndex] - currentIndex; // newdistanceJ -> currentValMinusIndex
            const int currentValPlusIndex = values[currentIndex] + currentIndex; // newdistanceI -> currentValPlusIndex
            
            maxScore = max(maxScore, maxValPlusIndex + currentValMinusIndex);
            maxValPlusIndex = max(maxValPlusIndex, currentValPlusIndex);
        }

        assert(maxScore != numeric_limits<int>::min());
        return maxScore;
    }
};

// https://leetcode.com/problems/best-sightseeing-pair/description/?envType=daily-question&envId=2024-12-27
