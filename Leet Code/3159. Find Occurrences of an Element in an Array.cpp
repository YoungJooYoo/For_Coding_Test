class Solution 
{
public:
    vector<int> occurrencesOfElement(const vector<int>& nums, const vector<int>& queries, const int x) 
    {
        vector<int> occurrences;
        
        // nums 배열에서 x의 발생 위치를 기록
        for (int i = 0; i < nums.size(); ++i) 
        {
            if (nums[i] == x) 
            {
                occurrences.push_back(i);
            }
        }
        
        vector<int> result;
        // 각 쿼리에 대해 결과 계산
        for (const int query : queries) 
        {
            if (query <= occurrences.size()) 
            {
                result.push_back(occurrences[query - 1]);
            } 
            else 
            {
                result.push_back(-1);
            }
        }
        
        return result;
    }
};

// https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/description/

/*

문제 설명
주어진 정수 배열 nums, 정수 배열 queries, 그리고 정수 x가 있습니다.

각 queries[i]에 대해 nums 배열에서 x의 queries[i]번째 발생의 인덱스를 찾아야 합니다. 만약 x가 queries[i]번 미만으로 발생한다면, 해당 쿼리에 대한 답은 -1이어야 합니다.

정수 배열 answer를 반환하세요. 이 배열은 모든 쿼리에 대한 답을 포함합니다.

예제
예제 1:

입력: nums = [1,3,1,7], queries = [1,3,2,4], x = 1
출력: [0, -1, 2, -1]
설명:
첫 번째 쿼리: 1의 첫 번째 발생은 인덱스 0에 있습니다.
두 번째 쿼리: 1은 nums에 두 번만 발생하므로 답은 -1입니다.
세 번째 쿼리: 1의 두 번째 발생은 인덱스 2에 있습니다.
네 번째 쿼리: 1은 nums에 두 번만 발생하므로 답은 -1입니다.
예제 2:

입력: nums = [1,2,3], queries = [10], x = 5
출력: [-1]
설명:
첫 번째 쿼리: 5는 nums에 존재하지 않으므로 답은 -1입니다.
제약 조건
1 <= nums.length, queries.length <= 10^5
1 <= queries[i] <= 10^5
1 <= nums[i], x <= 10^4
풀이 방향
nums 배열에서 x의 모든 발생 위치를 기록합니다.
각 queries[i]에 대해 x의 queries[i]번째 발생 위치를 찾습니다.
발생 위치를 기록한 배열의 길이가 queries[i]보다 작으면 -1을 반환합니다.
그렇지 않으면 해당 발생 위치를 반환합니다.
*/
