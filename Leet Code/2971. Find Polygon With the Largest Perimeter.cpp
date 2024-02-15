class Solution {
public:
    long long largestPerimeter(vector<int>& nums) 
    {
        sort(begin(nums), end(nums));

        const size_t ARRAY_LENGTH = nums.size();
        long long sum = 0;

        for (size_t i = 0; i < ARRAY_LENGTH; ++i) {
            sum += nums[i];
        }

        for (int i = ARRAY_LENGTH - 1; i >= 0; --i) {
            sum -= nums[i];
            if (nums[i] < sum) {
                return sum + nums[i];
            }
        }

        return -1;  
    }
};

/*
1. 정렬
코드는 sort(begin(nums), end(nums))를 사용하여 nums 벡터를 오름차순으로 정렬합니다. 이것은 작은 변이 먼저 고려되도록 하여 유효한 조합을 찾는 것을 더 쉽게 만듭니다.

2. 총 합 계산
변수 sum은 0으로 초기화된 후 첫 번째 루프는 정렬된 nums 벡터를 반복하며 각 요소를 sum에 추가합니다. 이것은 배열의 모든 변의 총 합을 계산합니다.

3. 가장 큰 변에서 반복
두 번째 루프는 가장 큰 변 (ARRAY_LENGTH - 1)부터 가장 작은 변 (0)까지 반복됩니다. 이는 더 긴 변이 유효한 다각형을 형성할 가능성이 더 높기 때문에 먼저 확인하기 때문입니다.

4. 다각형 조건 확인
두 번째 루프의 각 반복에서:
현재 변의 길이 (nums[i])는 sum에서 뺍니다. 이것은 나머지 변의 합을 나타냅니다.
조건 nums[i] < sum이 확인됩니다. 이 조건은 현재 변이 나머지 변의 합보다 짧다는 것을 확인합니다. 이는 다각형을 형성하는 데 필요한 조건입니다.
조건이 충족되면 현재 변과 나머지 변을 사용하여 유효한 다각형을 만들 수 있다는 의미입니다. 코드는 sum + nums[i]를 반환합니다. 이는 다각형의 둘레입니다.

5. 다각형 없음 처리
루프가 유효한 다각형을 찾지 못하고 완료되면 다각형을 형성할 수 있는 조합이 없다는 의미입니다. 코드는 -1을 반환하여 이를 나타냅니다.

주요 내용
정렬: 정렬은 작은 변을 먼저 고려하여 유효한 다각형을 효율적으로 찾는 데 중요합니다.
가장 큰 변에서 반복: 가장 큰 변부터 시작하면 잠재적인 다각형을 위해 더 긴 변을 우선 순위로 지정하는 데 도움이 됩니다.
다각형 조건: 조건 nums[i] < sum은 다각형의 기본 속성을 직접 확인합니다. 즉, 가장 긴 변은 다른 변의 합보다 짧아야 합니다.
둘레 반환: 코드는 단순히 다각형의 존재를 나타내는 부울 값이 아닌 찾은 다각형의 실제 둘레를 반환합니다.
다각형 없음 처리: 코드는 다각형을 형성할 수 없는 경우를 우아하게 처리합니다.

*/

// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/?envType=daily-question&envId=2024-02-15
