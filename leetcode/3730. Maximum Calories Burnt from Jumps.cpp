class Solution
{
public:
    long long maxCaloriesBurnt(vector<int>& heights) const
    {
        assert(MIN_LENGTH <= heights.size() && heights.size() <= MAX_LENGTH);

        vector<int> result;
        result.reserve(heights.size());
        int left = 0;
        int right = static_cast<int>(heights.size()) - 1;
        bool pickMax = true;

        ranges::sort(heights);
        while (left <= right) // 큰 값, 작은 값 교차 삽입
        {
            if (pickMax == true)
            {
                result.push_back(heights[right--]);
            }
            else
            {
                result.push_back(heights[left++]);
            }
            pickMax = !pickMax;
        }

        long long totalCalories = 0;
        int prevHeight = 0; // ground (height 0)

        for (const int height : result)
        {
            const long long diff = static_cast<long long>(prevHeight - height);
            totalCalories += (diff * diff);
            prevHeight = height;
        }

        return totalCalories;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,
        MIN_HEIGHT = 1,
        MAX_HEIGHT = 100000
    };
};


/*

🧗‍♀️ 3730. 점프를 통해 소모할 수 있는 최대 칼로리

난이도: 중간 (Medium)
주제: 시뮬레이션, 그리디, 수학

🧩 문제 설명

정수 배열 heights가 주어집니다.
이 배열의 크기는 n이며, heights[i]는 운동 루틴에서 i번째 블록의 높이를 나타냅니다.

당신은 **지면(높이 0)**에서 시작하며,
각 블록을 정확히 한 번씩 점프해야 합니다.
즉, 모든 블록을 단 한 번씩 밟는 점프 순서를 정해야 합니다.

점프 시 소모되는 칼로리는 다음과 같이 계산됩니다:

어떤 블록 높이 a에서 다른 블록 높이 b로 점프할 때:
소모 칼로리 = (a - b)²

처음 지면(0)에서 선택한 첫 번째 블록 heights[i]로 점프할 때:
소모 칼로리 = (0 - heights[i])²

당신의 목표는 최대한 많은 칼로리를 소모하도록 점프 순서를 정하는 것입니다.
즉, 최대 총 칼로리 합을 구하세요.

⚠️ 주의:
한 번 블록 위로 올라간 뒤에는 지면(0) 으로 다시 돌아갈 수 없습니다.

💡 예제 1

입력:
heights = [1, 7, 9]

출력:
181

설명:
가장 최적의 점프 순서는 [9, 1, 7]입니다.

지면(0) → 높이 9: (0 - 9)² = 81

9 → 1: (9 - 1)² = 64

1 → 7: (1 - 7)² = 36

총 소모 칼로리 = 81 + 64 + 36 = 181

💡 예제 2

입력:
heights = [5, 2, 4]

출력:
38

설명:
최적의 점프 순서는 [5, 2, 4]입니다.

지면(0) → 5: (0 - 5)² = 25

5 → 2: (5 - 2)² = 9

2 → 4: (2 - 4)² = 4

총 소모 칼로리 = 25 + 9 + 4 = 38

💡 예제 3

입력:
heights = [3, 3]

출력:
9

설명:
최적의 점프 순서는 [3, 3]입니다.

지면(0) → 3: (0 - 3)² = 9

3 → 3: (3 - 3)² = 0

총 소모 칼로리 = 9 + 0 = 9

⚙️ 제약 조건

1 ≤ n = heights.length ≤ 10⁵

1 ≤ heights[i] ≤ 10⁵
*/
