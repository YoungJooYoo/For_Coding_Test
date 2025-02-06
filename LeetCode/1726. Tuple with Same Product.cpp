#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution 
{
public:
    int tupleSameProduct(const vector<int>& nums) 
    {
        const size_t arraySize = nums.size();
        unordered_map<int, int> productFrequency;
        int totalTuples = 0;

        assert(MIN_LENGTH <= arraySize && arraySize <= MAX_LENGTH);
        for (size_t i = 0; i < arraySize; i++)
        {

            assert(MIN_VALUE <= nums[i] && nums[i] <= MAX_VALUE);
            for (size_t j = i + 1; j < arraySize; j++)
            {
                const int product = nums[i] * nums[j];
                ++productFrequency[product];
            }
        }
        
        for (const auto& [product, frequency] : productFrequency)
        {
            totalTuples += MULTIPLIER * frequency * (frequency - 1);
        }

        return totalTuples;
    }

private:
    enum 
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 1000,
        MIN_VALUE = 1,
        MAX_VALUE = 10000,
        MULTIPLIER = 4
    };
};

// https://leetcode.com/problems/tuple-with-same-product/description/?envType=daily-question&envId=2025-02-06
