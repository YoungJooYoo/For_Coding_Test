class Solution 
{
public:
    string largestNumber(const vector<int>& nums) 
    {
        vector<string> numbers;
        string result;a

        for (const auto num : nums)
        {
            numbers.push_back(to_string(num));
        }

        sort(numbers.begin(), numbers.end(), [&](const string& a, const string& b) -> bool {
            return a + b > b + a;
        });

        for (const auto& num : numbers)
        {
            result += num;
        }
        
        return (result[0] == '0') ? "0" : result;
    }
};

// https://leetcode.com/problems/largest-number/description/?envType=company&envId=google&favoriteSlug=google-three-months&status=TO_DO&difficulty=MEDIUM
