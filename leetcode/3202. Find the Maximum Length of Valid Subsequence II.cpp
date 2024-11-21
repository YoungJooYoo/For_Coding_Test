class Solution 
{
public:
    int maximumLength(const vector<int>& nums, const int k) const
    {
        const size_t length = nums.size();
        vector<vector<int>> dp(length, vector<int>(k, 1));
        // dp[i][remainder]는 나머지가 remainder인 i에서 끝나는 부분 수열의 최대 길이입니다.
        // dp[i][remainder] = dp[j][remainder] + 1
        // 여기서 remainder = (nums[i] + nums[j]) % k

        int maxLength = 0;
        for (size_t i = 0; i < length; ++i)
        {
            for (size_t j = 0; j < i; ++j)
            {
                const int remainder = (nums[i] + nums[j]) % k;
                dp[i][remainder] = dp[j][remainder] + 1;
                maxLength = max(maxLength, dp[i][remainder]);
            }
        }

        return maxLength;
    }
};

// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/
/*

3202. 유효한 부분 수열의 최대 길이 찾기 II
난이도: 중간

정수 배열 nums와 양의 정수 k가 주어집니다.

배열 nums의 길이 x인 부분 수열(subsequence) sub가 다음 조건을 만족하면 유효한(valid) 부분 수열이라고 합니다:

(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
주어진 nums의 가장 긴 유효한 부분 수열의 길이를 반환하세요.

예제 1:
입력:

nums = [1, 2, 3, 4, 5], k = 2
출력:

5
설명:

가장 긴 유효한 부분 수열은 [1, 2, 3, 4, 5]입니다.

예제 2:
입력:

nums = [1, 4, 2, 3, 1, 4], k = 3
출력:

4
설명:

가장 긴 유효한 부분 수열은 [1, 4, 1, 4]입니다.

제약 사항:
2 <= nums.length <= 10^3
1 <= nums[i] <= 10^7
1 <= k <= 10^3
이 문제는 배열 내의 특정 조건을 만족하는 가장 긴 부분 수열을 찾아야 하는 문제입니다. 모든 인접한 두 요소의 합이 같은 나머지를 갖도록 부분 수열을 구성하는 것이 핵심입니다.

*/
