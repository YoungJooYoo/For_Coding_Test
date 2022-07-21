class Solution 
{
public:
    int minPartitions(string n) 
    {
        int result = 0;
        
        for (const auto& i : n) {
            result = max(result, i - '0');
        }
        
        return result;
    }
};