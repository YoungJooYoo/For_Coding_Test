class Solution
{
public:
    vector<int> sortByReflection(vector<int>& numbers) const
    {
        const size_t LENGTH = numbers.size();
        vector<pair<int, int>> reflectedValues;
        reflectedValues.reserve(LENGTH);

        assert(MIN_LENGTH <= LENGTH && LENGTH <= MAX_LENGTH);

        for (size_t i = 0; i < LENGTH; ++i)
        {
            const int value = numbers[i];
            string binaryReversed;
            int temp = value;
            while (temp != 0)
            {
                binaryReversed.push_back((temp % 2) + '0'); // LSB → MSB
                temp /= 2;
            }
            int reflected = 0; // Convert reversed binary string → decimal
            for (const char ch : binaryReversed)
            {
                const int bit = ch - '0';
                reflected = (reflected * 2) + bit;
            }
            reflectedValues.push_back({reflected, value});
            assert(MIN_NUMBER <= value && value <= MAX_NUMBER);
        }

        ranges::sort(reflectedValues);
        size_t idx = 0; // Fill back into numbers array
        for (const auto& [refVal, original] : reflectedValues)
        {
            numbers[idx++] = original;
        }

        assert(reflectedValues.size() == numbers.size() && numbers.size() == LENGTH);
        return numbers;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_NUMBER = 1,
        MAX_NUMBER = 1000000000
    };
};

// https://leetcode.com/problems/sort-integers-by-binary-reflection/description/
