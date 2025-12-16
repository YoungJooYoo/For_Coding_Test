class Solution 
{
public:
    vector<long long> findPrefixScore(vector<int>& nums) const
    {
        assert(MIN_LENGTH <= nums.size() && nums.size() <= MAX_LENGTH);

        const size_t LENGTH = nums.size();
        vector<long long> ans(LENGTH, 0);
        long long currentMax = 0;   
        long long currentScore = 0; 

        for (size_t i = 0; i < LENGTH; ++i)
        {
            assert(MIN_NUM <= nums[i] && nums[i] <= MAX_NUM);
            currentMax = max(currentMax, static_cast<long long>(nums[i]));
            const long long converVal = nums[i] + currentMax;
            currentScore += converVal;
            ans[i] = currentScore;
        }

        assert(nums.size() == ans.size());
        return ans;
    }

private:
    enum
    {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,
        MIN_NUM = 1,
        MAX_NUM = 1000000000
    };
};

/*
https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/description/

**[2640. 배열의 모든 접두사 점수 구하기]**

배열 `arr`의 **변환 배열(conversion array)** `conver`를 다음과 같이 정의합니다:

*   `conver[i] = arr[i] + max(arr[0..i])`
*   여기서 `max(arr[0..i])`는 `0 <= j <= i` 범위 내 `arr[j]`의 최댓값을 의미합니다.

또한 배열 `arr`의 **점수(score)**는 `arr`의 변환 배열(`conver`)의 모든 값의 합으로 정의합니다.

길이가 `n`인 0부터 시작하는(0-indexed) 정수 배열 `nums`가 주어집니다. 길이가 `n`인 배열 `ans`를 반환하세요. 이때 `ans[i]`는 접두사 `nums[0..i]`의 점수여야 합니다.

**예제 1:**

*   **입력:** `nums = [2,3,7,5,10]`
*   **출력:** `[4,10,24,36,56]`
*   **설명:**
    *   접두사 `[2]`의 경우, 변환 배열은 `[4]`이므로 점수는 4입니다.
    *   접두사 `[2, 3]`의 경우, 변환 배열은 `[4, 6]`이므로 점수는 10입니다.
    *   접두사 `[2, 3, 7]`의 경우, 변환 배열은 `[4, 6, 14]`이므로 점수는 24입니다.
    *   접두사 `[2, 3, 7, 5]`의 경우, 변환 배열은 `[4, 6, 14, 12]`이므로 점수는 36입니다.
    *   접두사 `[2, 3, 7, 5, 10]`의 경우, 변환 배열은 `[4, 6, 14, 12, 20]`이므로 점수는 56입니다.

**예제 2:**

*   **입력:** `nums = [1,1,2,4,8,16]`
*   **출력:** `[2,4,8,16,32,64]`
*   **설명:**
    *   접두사 `[1]`의 경우, 변환 배열은 `[2]`이므로 점수는 2입니다.
    *   접두사 `[1, 1]`의 경우, 변환 배열은 `[2, 2]`이므로 점수는 4입니다.
    *   접두사 `[1, 1, 2]`의 경우, 변환 배열은 `[2, 2, 4]`이므로 점수는 8입니다.
    *   ... (이하 생략) ...

**제약 조건:**

*   `1 <= nums.length <= 10^5`
*   `1 <= nums[i] <= 10^9`
*/
