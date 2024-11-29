class Solution 
{
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) 
    {
        const size_t TOTAL_COST =  accumulate(cost.begin(), cost.end(), 0);
        const size_t TOTAL_GAS = accumulate(gas.begin(), gas.end(), 0);
        const size_t LENGTH = gas.size();

        if (TOTAL_GAS < TOTAL_COST)
        {
            return FAIL;
        }

        size_t start = 0;
        int currrentGas = 0;
        for (size_t i = 0; i < LENGTH; ++i)
        {
            if (currrentGas < 0)
            {
                start = i;
                currrentGas ^= currrentGas; // init 0
            }
            currrentGas +=(gas[i] - cost[i]);
        }

        return static_cast<int>(start);
    }

private:
    enum { FAIL = -1 };
};

// https://leetcode.com/problems/gas-station/description/?envType=company&envId=salesforce&favoriteSlug=salesforce-thirty-days
