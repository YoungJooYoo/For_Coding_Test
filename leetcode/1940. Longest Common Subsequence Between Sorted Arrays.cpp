class Solution 
{
public:
    vector<int> longestCommonSubsequence(const vector<vector<int>>& arrays) 
    {
        vector<int> result;
        unordered_map<int ,int> freq;

        for (const auto& array : arrays)
        {
            for (const auto num : array)
            {
                ++freq[num];
            }
        }

        for (const auto& elem : freq)
        {
            if (elem.second == arrays.size() && elem.second > 1)
            {
                result.push_back(elem.first);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};

// https://leetcode.com/problems/longest-common-subsequence-between-sorted-arrays/

/*
번역: 1940. 정렬된 배열들 간의 가장 긴 공통 부분 수열 난이도: 중간 주제 힌트 정수 배열들의 배열 arrays가 주어집니다. 각 arrays[i]는 엄격하게 증가하는 순서로 정렬되어 있습니다. 모든 배열 간의 가장 긴 공통 부분 수열을 나타내는 정수 배열을 반환하세요.

부분 수열은 다른 배열에서 몇몇 요소들(없을 수도 있음)을 삭제하여 나머지 요소들의 순서를 바꾸지 않고 얻을 수 있는 수열입니다.

예제 1:
입력:

lua
코드 복사
arrays = [[1,3,4],
          [1,4,7,9]]
출력: [1,4]
설명: 두 배열에서 가장 긴 공통 부분 수열은 [1,4]입니다.

예제 2:
입력:

lua
코드 복사
arrays = [[2,3,6,8],
          [1,2,3,5,6,7,10],
          [2,3,4,6,9]]
출력: [2,3,6]
설명: 세 배열에서 가장 긴 공통 부분 수열은 [2,3,6]입니다.

예제 3:
입력:

lua
코드 복사
arrays = [[1,2,3,4,5],
          [6,7,8]]
출력: []
설명: 두 배열 간에 공통된 부분 수열이 없습니다.

제한 사항:
2 <= arrays.length <= 100
1 <= arrays[i].length <= 100
1 <= arrays[i][j] <= 100
arrays[i]는 엄격하게 증가하는 순서로 정렬되어 있습니다.
문제 설명:
이 문제는 주어진 여러 정렬된 배열들에서 가장 긴 공통 부분 수열을 찾아야 하는 문제입니다. 즉, 모든 배열에서 동일하게 나타나는 숫자들을 찾아서 순서를 유지한 상태로 반환해야 합니다.

예를 들어, 첫 번째 예제에서는 두 배열에서 모두 나타나는 수는 [1, 4]입니다. 두 번째 예제에서는 세 배열에서 모두 나타나는 수는 [2, 3, 6]입니다.


*/
