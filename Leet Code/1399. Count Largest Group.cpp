class Solution {
public:
    // 각 자리수의 합을 계산하는 함수
    int digitSum(int num) const 
    {
        int sum = 0;

        while (num > 0) {
            const int remainder = num % 10;
            num /= 10;
            sum += remainder;
        }

        return sum;
    }
    
    // 가장 큰 그룹에 속하는 숫자들의 수를 반환하는 함수
    int countLargestGroup(const int n) const 
    {
        unordered_map<int, int> digitSumFreq;

        // 각 숫자의 자리수 합을 카운트
        for (int i = 1; i <= n; ++i) {
            ++digitSumFreq[digitSum(i)];
        }
        
        // 가장 큰 그룹의 크기를 찾음
        int maxFreq = INT_MIN;
        for (const auto& entry : digitSumFreq) {
            maxFreq = max(maxFreq, entry.second);
        }
        
        // 가장 큰 그룹의 크기와 동일한 그룹의 수를 찾음
        int groupCount = 0;
        for (const auto& entry : digitSumFreq) {
            if (entry.second == maxFreq) {
                ++groupCount;
            }
        }
        
        return groupCount;
    }
};

// https://leetcode.com/problems/count-largest-group/
