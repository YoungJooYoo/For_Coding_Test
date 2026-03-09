class Solution
{
public:
    int minimumIndex(const vector<int>& capacity, const int itemSize) const
    {
        assert(MIN_LENGTH <= capacity.size() && capacity.size() <= MAX_LENGTH);
        assert(MIN_ITEM_SIZE <= itemSize && itemSize <= MAX_ITEM_SIZE);

        const size_t LENGTH = capacity.size();
        int minIndex = NO_ANSWER;
        int minCapacity = numeric_limits<int>::max();

        for (size_t i = 0; i < LENGTH; ++i)
        {
            const int currentCapacity = capacity[i];
            assert(MIN_CAPACITY <= currentCapacity && currentCapacity <= MAX_CAPACITY);

            if (currentCapacity >= itemSize)
            {
                if (currentCapacity < minCapacity)
                {
                    minCapacity = currentCapacity;
                    minIndex = static_cast<int>(i);
                }
            }
        }

        return minIndex;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        MIN_CAPACITY = 1,
        MAX_CAPACITY = 100,
        MIN_ITEM_SIZE = 1,
        MAX_ITEM_SIZE = 100,

        NO_ANSWER = -1
    };
};



/*
문제: 최소 용량 박스 찾기

정수 배열 capacity가 주어집니다.
capacity[i]는 i번째 박스의 수용 용량을 의미합니다.

또한 정수 itemSize가 주어지며, 이는 넣으려는 물건의 크기입니다.

어떤 박스 i는 다음 조건을 만족하면 물건을 담을 수 있습니다.

capacity[i] >= itemSize

즉, 박스의 용량이 물건 크기 이상이면 저장 가능합니다.

목표

물건을 담을 수 있는 박스들 중에서 가장 작은 용량을 가진 박스의 인덱스를 반환하세요.

조건이 여러 개일 경우 규칙은 다음과 같습니다.

물건을 담을 수 있는 박스 중 용량이 가장 작은 박스를 선택합니다.

그런 박스가 여러 개라면 인덱스가 가장 작은 것을 반환합니다.

만약 물건을 담을 수 있는 박스가 없다면 -1을 반환합니다.
*/
