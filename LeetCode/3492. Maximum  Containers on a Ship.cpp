
class Solution 
{
public:
    int maxContainers(const int n, const int w, const int maxWeight) const 
    {
        assert(n >= MIN_N && n <= MAX_N);
        assert(w >= MIN_WEIGHT && w <= MAX_WEIGHT);
        assert(maxWeight >= MIN_MAX_WEIGHT && maxWeight <= MAX_MAX_WEIGHT);
        
        const int totalCells = n * n;
        int containersLoaded = 0;
        int currentTotalWeight = 0;
        
        for (int i = 1; i <= totalCells; ++i) 
        {
            if (currentTotalWeight + w <= maxWeight) 
            {
                currentTotalWeight += w;
                containersLoaded = i;
            } 
            else 
            {
                break;
            }
        }
        
        return containersLoaded;
    }

private:
    enum {
        MIN_N = 1,
        MAX_N = 1000,
        MIN_WEIGHT = 1,
        MAX_WEIGHT = 1000,
        MIN_MAX_WEIGHT = 1,
        MAX_MAX_WEIGHT = 1000000000
    };
};


// https://leetcode.com/problems/maximum-containers-on-a-ship/description/
