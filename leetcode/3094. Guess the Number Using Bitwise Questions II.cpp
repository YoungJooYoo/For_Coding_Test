#define BIT_MASK(pos) (1 << pos)

class Solution 
{
public:
    int findNumber() 
    {
        const int INITIAL_NUM = 0;
        const int initialCount = commonBits(INITIAL_NUM); // 초기 cnt 값
        
        int result = 0;
        for (const int bitPosition : BIT_POSITIONS) 
        {
            const int currentBit = BIT_MASK(bitPosition);
            const int currentCount = commonBits(currentBit);
            if (currentCount > initialCount) 
            {
                result |= currentBit;
            }
            commonBits(currentBit);
        }
        return result;
    }

private:
    enum BitPositions 
    {
        BIT0 = 0,
        BIT1 = 1,
        BIT2 = 2,
        BIT3 = 3,
        BIT4 = 4,
        BIT5 = 5,
        BIT6 = 6,
        BIT7 = 7,
        BIT8 = 8,
        BIT9 = 9,
        BIT10 = 10,
        BIT11 = 11,
        BIT12 = 12,
        BIT13 = 13,
        BIT14 = 14,
        BIT15 = 15,
        BIT16 = 16,
        BIT17 = 17,
        BIT18 = 18,
        BIT19 = 19,
        BIT20 = 20,
        BIT21 = 21,
        BIT22 = 22,
        BIT23 = 23,
        BIT24 = 24,
        BIT25 = 25,
        BIT26 = 26,
        BIT27 = 27,
        BIT28 = 28,
        BIT29 = 29
    };
    
    // 매직 넘버를 비트 마스크로 변환하는 매크로
    
    
    // 가독성을 위해 비트 포지션을 순회할 수 있는 벡터
    const vector<int> BIT_POSITIONS = 
    {
        BIT0, BIT1, BIT2, BIT3, BIT4, BIT5, BIT6, BIT7, BIT8, BIT9,
        BIT10, BIT11, BIT12, BIT13, BIT14, BIT15, BIT16, BIT17, BIT18,
        BIT19, BIT20, BIT21, BIT22, BIT23, BIT24, BIT25, BIT26, BIT27,
        BIT28, BIT29
    };
};

// https://leetcode.com/problems/guess-the-number-using-bitwise-questions-ii/description/
