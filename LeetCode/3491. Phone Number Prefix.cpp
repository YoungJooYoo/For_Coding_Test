class Solution 
{
public:
    bool phonePrefix(const vector<string>& numbers) const 
    {
        assert(numbers.size() >= MIN_PHONE_COUNT && numbers.size() <= MAX_PHONE_COUNT);
        const size_t totalNumbers = numbers.size();

        for (size_t i = 0; i < totalNumbers; ++i)
        {
            const string& currentPhone = numbers[i];
            const size_t currentLength = currentPhone.size();
            assert(currentLength >= MIN_PHONE_LENGTH && currentLength <= MAX_PHONE_LENGTH);
            for (size_t j = 0; j < totalNumbers; ++j)
            {
                if (i == j) continue;
                const string& otherPhone = numbers[j];
                if (currentLength <= otherPhone.size() && otherPhone.substr(0, currentLength) == currentPhone)
                {
                    return false;
                }
            }
        }

        return true;
    }

private:
    enum
    {
        MIN_PHONE_COUNT = 2,
        MAX_PHONE_COUNT = 50,
        MIN_PHONE_LENGTH = 1,
        MAX_PHONE_LENGTH = 50
    };
};

// https://leetcode.com/problems/phone-number-prefix/description/
