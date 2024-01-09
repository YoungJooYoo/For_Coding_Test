class Solution {
public:
    int alternatingSubarray(const vector<int>& nums) 
    {
        const size_t LEN = nums.size();
        int max_len = 0; // 최대 길이 저장

        for (int i = 1; i < LEN; ++i) {
            int ans = 1; // 현재 시작점에서의 길이
            for (int j = i; j < LEN; ++j) {
                const int diff = nums[j] - nums[j - 1]; // 인접 원소 간의 차이
                if ((diff == 1 && (j - i) % 2 == 0) || (diff == -1 && (j - i) % 2 == 1))  ++ans;// 번갈아 나타나는 패턴 확인
                else break; // 패턴이 깨지면 반복 중단
            }
            max_len = max(max_len, ans); // 최대 길이 갱신
        }

        return (max_len > 1) ? max_len : NO_EXIST; // 결과 반환, 배열이 비었으면 -1
    }

private:
    enum { NO_EXIST = - 1 };
};

/*

1. **번역**: 
0부터 시작하는 인덱스를 가진 정수 배열 `nums`가 주어집니다. 길이가 `m`인 부분 배열 `s`가 다음 조건을 만족하면 번갈아 나타난다고 합니다:
   - `m`은 1보다 큽니다.
   - `s[1] = s[0] + 1`.
   - 0부터 시작하는 부분 배열 `s`는 `[s[0], s[1], s[0], s[1], ..., s[m-1] % 2]`와 같은 모양을 띕니다. 다시 말해, `s[1] - s[0] = 1`, `s[2] - s[1] = -1`, `s[3] - s[2] = 1`, `s[4] - s[3] = -1`, ... , `s[m - 1] - s[m - 2] = (-1)^m`입니다.
   - `nums`에 존재하는 모든 번갈아 나타나는 부분 배열 중 최대 길이를 반환하거나, 그러한 부분 배열이 없으면 -1을 반환합니다.


2. **요약**: 
이 문제는 주어진 배열 `nums`에서 번갈아 나타나는 부분 배열의 최대 길이를 찾는 것입니다. 번갈아 나타난다는 것은 인접한 원소들이 1과 -1을 번갈아 가면서 차이를 보이는 것을 의미합니다.


3. **문제 풀이 방향**: 
배열을 순회하면서 인접한 원소들이 1 또는 -1의 차이를 보이는지 확인합니다. 이때 최대 길이를 갱신하는 방식으로 진행하며, 해당 조건을 만족하지 않을 경우, 부분 배열의 길이를 리셋하고 새로운 부분 배열의 시작점으로 간주합니다.

*/

// https://leetcode.com/problems/longest-alternating-subarray/description/
