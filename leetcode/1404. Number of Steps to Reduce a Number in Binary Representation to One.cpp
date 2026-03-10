class Solution
{
public:
    int numSteps(string& binary) const
    {
        // 입력값 검증
        assert(MIN_LENGTH <= binary.size() && binary.size() <= MAX_LENGTH);
        assert(binary.front() == '1');

        int stepCount = 0;

        while (binary != "1")
        {
            const size_t LENGTH = binary.size();
            if (binary.back() == '0') // 짝수 → 2로 나누기
            {
                binary.pop_back();
            }
            else // 홀수 → +1 처리 (carry 발생)
            {
                int index = static_cast<int>(LENGTH) - 1;
                assert(binary[index] == '0' || binary[index] == '1');
                while (index >= 0 && binary[index] == '1')
                {
                    binary[index] = '0';
                    --index;
                }

                if (index >= 0)
                {
                    binary[index] = '1';
                }
                else
                {
                    binary = '1' + binary;
                }
            }

            ++stepCount;
        }

        return stepCount;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 500
    };
};

// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2026-02-26
