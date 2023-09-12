class Solution {
public:
    int missingNumber(vector<int>& arr) 
    {
        const int END = arr.size() - 1;
        const int range = arr[END] - arr[0]; // 끝과 시작 차이 얼마인지 계산
        int interval = range / (END + 1); // 차이 나는 만큼 인덱스를 구해 수열 패턴 찾기

        int start = arr[0];
        for (const auto& elem : arr) {
            if (start != elem) return start; // 존재 하지 않는 원소면 반환
            start += interval;
        }

        return arr[0]; // 모든 값이 같은 경우, 배열의 아무값 반환
    }
};

// https://leetcode.com/problems/missing-number-in-arithmetic-progression/description/
