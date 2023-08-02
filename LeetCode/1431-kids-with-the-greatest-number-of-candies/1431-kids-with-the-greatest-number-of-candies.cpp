class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool> result;
        
        int max = *max_element(candies.begin(), candies.end());
        
        for (const auto& candy : candies) {
            if (candy + extraCandies >= max) result.push_back(true);
            else result.push_back(false);
        }
        
        return result;
    }
};