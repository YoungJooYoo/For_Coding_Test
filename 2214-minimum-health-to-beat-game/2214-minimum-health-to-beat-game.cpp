class Solution 
{
public:
    long long minimumHealth(vector<int>& damage, int armor) 
    {
        long long result = 0;
        
        sort(damage.begin(), damage.end(), [](int i, int j) { return j < i; });
        
        result = damage[0] - armor;
        result = result < 0 ? 0 : result;
        
        for (const auto& ele : damage) {
            result += ele;
        }
        
        return result - damage[0] + 1;
    }
};