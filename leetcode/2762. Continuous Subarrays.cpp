class Solution 
{
public:
    static long long continuousSubarrays(const vector<int>& nums) 
    {
        const int ARRAY_LENGTH = nums.size();
        long long totalCount = 0; // 결과로 반환할 총 연속 부분 배열의 개수
        map<int, int> windowElements; // 현재 윈도우의 숫자와 그 개수를 저장
 
        for (int left = 0, right = 0; right < ARRAY_LENGTH; ++right) 
        {
            // 현재 숫자를 윈도우에 추가
            ++windowElements[nums[right]];

            // 윈도우 조건이 깨지면 왼쪽 포인터를 이동하여 윈도우 축소
            while (left < right && prev(windowElements.end())->first - windowElements.begin()->first > MAX) 
            {
                --windowElements[nums[left]];
                if (windowElements[nums[left]] == MIN) 
                {
                    windowElements.erase(nums[left]);
                }
                ++left;
            }

            // 현재 윈도우에서 가능한 모든 연속 부분 배열의 개수를 추가
            totalCount += static_cast<long long>(right - left + 1);
        }

        return totalCount;
    }

private:
    enum
    {
        MIN = 0,
        MAX = 2
    };
};


// https://leetcode.com/problems/continuous-subarrays/description/?envType=daily-question&envId=2024-12-14

/*
문제 번역: 2762. 연속 부분 배열 (Continuous Subarrays)

문제 설명
정수 배열 nums가 주어집니다. 배열의 한 부분 배열(subarray)이 **연속적(continuous)**이라고 불리려면 아래 조건을 만족해야 합니다:
	•	부분 배열의 인덱스가 ￼라고 할 때, 부분 배열 내 모든 ￼ (￼)에 대해 다음을 만족해야 합니다:
	•	￼

주어진 배열에서 모든 연속적인 부분 배열의 총 개수를 반환하세요.

**부분 배열(subarray)**는 배열 내에서 비어있지 않은 연속된 요소들의 서열(sequence)입니다.

예제

예제 1

입력: nums = [5,4,2,4]
출력: 8
설명: 
크기 1의 연속 부분 배열: [5], [4], [2], [4]
크기 2의 연속 부분 배열: [5,4], [4,2], [2,4]
크기 3의 연속 부분 배열: [4,2,4]
크기 4의 부분 배열은 연속적이지 않으므로 존재하지 않음.
연속적인 부분 배열의 총 개수 = 4 + 3 + 1 = 8

예제 2

입력: nums = [1,2,3]
출력: 6
설명:
크기 1의 연속 부분 배열: [1], [2], [3]
크기 2의 연속 부분 배열: [1,2], [2,3]
크기 3의 연속 부분 배열: [1,2,3]
연속적인 부분 배열의 총 개수 = 3 + 2 + 1 = 6

제약 조건
	•	￼
	•	￼

핵심 요약 및 전략
	•	연속적(Continuous)의 정의: 부분 배열 내 모든 쌍의 원소에 대해 차이가 2 이하인지 확인.
	•	슬라이딩 윈도우를 활용해 효율적으로 해결:
	1.	배열을 탐색하며 조건에 맞는 윈도우 크기를 확장.
	2.	조건이 만족되지 않을 경우 윈도우를 축소.
	•	최종적으로 모든 연속 부분 배열의 개수를 계산.

*/
