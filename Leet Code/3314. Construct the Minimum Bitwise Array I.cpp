class Solution 
{
public:
    vector<int> minBitwiseArray(const vector<int>& nums) 
    {
        const size_t LENGTH = nums.size();
        vector<int> ans;

        for (size_t i = 0; i < LENGTH; ++i)
        {
            int candidate = 0; // 변수 이름 변경
            bool bIsFound = false;
            while (candidate <= nums[i])
            {
                const int val = candidate | (candidate + 1);
                if (val == nums[i])
                {
                    ans.push_back(candidate);
                    bIsFound = true;
                    break;
                }
                ++candidate;
            }
            if (bIsFound == false)
            {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/

/*

3314. 최소 비트 연산 배열 구성하기 I


주어진 n개의 소수로 이루어진 정수 배열 nums가 있습니다.

각 인덱스 i에 대해, ans[i]와 ans[i] + 1의 비트 단위 OR 연산 결과가 nums[i]와 같도록 하는 길이 n의 배열 ans를 구성해야 합니다. 즉, 다음 조건을 만족해야 합니다:

css
코드 복사
ans[i] OR (ans[i] + 1) == nums[i]
추가로, 결과 배열에서 각 ans[i]의 값을 최소화해야 합니다.

만약 조건을 만족하는 ans[i] 값을 찾을 수 없다면, ans[i] = -1로 설정해야 합니다.

예제 1:
less
코드 복사
입력: nums = [2,3,5,7]
출력: [-1,1,4,3]
설명:

i = 0:
조건을 만족하는 ans[0] 값이 없으므로 ans[0] = -1입니다.
i = 1:
가장 작은 ans[1] 값으로 1을 선택하면, 1 OR (1 + 1) = 1 OR 2 = 3이 되어 조건을 만족합니다. 따라서 ans[1] = 1입니다.
i = 2:
가장 작은 ans[2] 값으로 4를 선택하면, 4 OR (4 + 1) = 4 OR 5 = 5가 되어 조건을 만족합니다. 따라서 ans[2] = 4입니다.
i = 3:
가장 작은 ans[3] 값으로 3을 선택하면, 3 OR (3 + 1) = 3 OR 4 = 7이 되어 조건을 만족합니다. 따라서 ans[3] = 3입니다.
예제 2:
less
코드 복사
입력: nums = [11,13,31]
출력: [9,12,15]
설명:

i = 0:
가장 작은 ans[0] 값으로 9를 선택하면, 9 OR (9 + 1) = 9 OR 10 = 11이 되어 조건을 만족합니다. 따라서 ans[0] = 9입니다.
i = 1:
가장 작은 ans[1] 값으로 12를 선택하면, 12 OR (12 + 1) = 12 OR 13 = 13이 되어 조건을 만족합니다. 따라서 ans[1] = 12입니다.
i = 2:
가장 작은 ans[2] 값으로 15를 선택하면, 15 OR (15 + 1) = 15 OR 16 = 31이 되어 조건을 만족합니다. 따라서 ans[2] = 15입니다.
제약 사항:
1 <= nums.length <= 100
2 <= nums[i] <= 1000
nums[i]는 소수입니다.
*/
