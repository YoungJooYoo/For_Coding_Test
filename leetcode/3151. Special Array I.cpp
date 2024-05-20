class Solution 
{
public:
    bool isArraySpecial(const vector<int>& nums) 
    {
        const size_t LENGTH = nums.size();

        for (size_t i = 0; i < LENGTH - 1; ++i) 
        {
            if ((nums[i] % 2 == 1 && nums[i + 1] % 2 == 1) or (nums[i] % 2 == 0 && nums[i + 1] % 2 == 0))
            {
                return false;
            }
        }

        return true;
    }
};

/*
3151. 특별한 배열 I

난이도: 쉬움

힌트:
배열의 인접한 요소 쌍의 모든 숫자가 서로 다른 짝수성을 가질 때 배열은 특별하다고 간주됩니다.

정수 배열 nums가 주어졌습니다. nums가 특별한 배열이면 true를 반환하고, 그렇지 않으면 false를 반환하세요.

예제
예제 1:

입력: nums = [1]

출력: true

설명:

요소가 하나뿐입니다. 따라서 정답은 true입니다.

예제 2:

입력: nums = [2,1,4]

출력: true

설명:

두 쌍의 요소가 있습니다: (2,1)과 (1,4). 두 쌍 모두 숫자들이 서로 다른 짝수성을 가집니다. 따라서 정답은 true입니다.

예제 3:

입력: nums = [4,3,1,6]

출력: false

설명:

nums[1]과 nums[2]가 모두 홀수입니다. 따라서 정답은 false입니다.

제약 조건
1 <= nums.length <= 100
1 <= nums[i] <= 100
문제 요약
주어진 정수 배열에서 인접한 요소들의 짝수성이 다른 경우 배열을 특별하다고 정의합니다. 주어진 배열이 특별한 배열인지 확인하는 문제입니다.

풀이 방향
배열의 길이가 1인 경우 무조건 true를 반환합니다. 배열에 인접한 요소 쌍이 없기 때문에 특별한 배열로 간주합니다.
배열을 순차적으로 탐색하면서 인접한 두 요소의 짝수성을 비교합니다.
만약 두 요소가 모두 홀수이거나 모두 짝수라면 false를 반환합니다.
배열의 모든 인접한 쌍을 검사한 후에도 문제가 없다면 true를 반환합니다.
*/

// https://leetcode.com/problems/special-array-i/description/
