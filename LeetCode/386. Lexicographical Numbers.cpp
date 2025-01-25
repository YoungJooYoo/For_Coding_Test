class Solution 
{
public:
    vector<int> lexicalOrder(const int n) 
    {
        assert(MIN_NUMBER <= n && n <= MAX_NUMBER);

        vector<int> lexicalNumbers(n, 0);
        vector<string> stringNumbers(n, "0");

        for (size_t index = 1; index <= n; ++index)
        {
            const string currentNumber(to_string(index));
            stringNumbers[index - 1] = currentNumber;
        }
        sort(stringNumbers.begin(), stringNumbers.end());

        size_t resultIndex = 0;
        for (const auto& stringNumber : stringNumbers)
        {
            lexicalNumbers[resultIndex++] = stoi(stringNumber);
        }

        return lexicalNumbers;
    }

private:
    enum
    {
        MIN_NUMBER = 1,
        MAX_NUMBER= 50000
    };
};

// https://leetcode.com/problems/lexicographical-numbers/description/
