class Solution
{
public:
    int minimumDistance(const vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        unordered_map<int, vector<int>> positions;
        int result = FAIL;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) // 각 숫자마다 등장 인덱스 저장
        {
            positions[nums[i]].push_back(i);
        }

        for (const auto& [num, indices] : positions) // 각 숫자별로 세 번 이상 등장하면 거리 계산
        {
            if (indices.size() < TARGET_SIZE)
            {
                continue;
            }
            const size_t LENGTH = indices.size();
            for (size_t a = 0; a < LENGTH - 2; ++a) // 가능한 (i, j, k) 조합 검사
            {
                for (size_t b = a + 1; b < LENGTH - 1; ++b)
                {
                    for (size_t c = b + 1; c < LENGTH; ++c)
                    {
                        const int distance =
                            abs(indices[a] - indices[b]) +
                            abs(indices[b] - indices[c]) +
                            abs(indices[c] - indices[a]);

                        if (result == FAIL || distance < result)
                        {
                            result = distance;
                        }
                    }
                }
            }
        }

        return result;
    }

private:
    enum
    {
        FAIL = -1,
        MIN_LENGTH = 1,
        MAX_LENGTH = 100,
        TARGET_SIZE = 3
    };
};

// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/

/*
3740. 동일한 세 요소 간의 최소 거리 I
힌트
정수 배열 nums가 주어집니다.

**좋은 튜플(good tuple)**은 nums[i] == nums[j] == nums[k]를 만족하는 세 개의 서로 다른 인덱스 (i, j, k)를 의미합니다.

좋은 튜플의 **거리(distance)**는 abs(i - j) + abs(j - k) + abs(k - i)로 정의됩니다. 여기서 abs(x)는 x의 절대값을 나타냅니다.

좋은 튜플의 가능한 최소 거리를 나타내는 정수를 반환하세요. 만약 좋은 튜플이 존재하지 않으면 -1을 반환하세요.

예시 1:

입력: nums = [1,2,1,1,3]
출력: 6
설명:
최소 거리는 좋은 튜플 (0, 2, 3)에 의해 달성됩니다.
(0, 2, 3)은 nums[0] == nums[2] == nums[3] == 1을 만족하므로 좋은 튜플입니다. 이 튜플의 거리는 abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6입니다.

예시 2:

입력: nums = [1,1,2,3,2,1,2]
출력: 8
설명:
최소 거리는 좋은 튜플 (2, 4, 6)에 의해 달성됩니다.
(2, 4, 6)은 nums[2] == nums[4] == nums[6] == 2를 만족하므로 좋은 튜플입니다. 이 튜플의 거리는 abs(2 - 4) + abs(4 - 6) + abs(6 - 2) = 2 + 2 + 4 = 8입니다.

예시 3:

입력: nums = [1]
출력: -1
설명:
좋은 튜플이 존재하지 않습니다. 따라서 답은 -1입니다.

제약 조건:

1 <= n == nums.length <= 100
1 <= nums[i] <= n





*/
