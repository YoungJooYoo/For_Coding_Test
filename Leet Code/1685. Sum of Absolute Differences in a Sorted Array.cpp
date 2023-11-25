class Solution {
public:
    // 이 함수는 시간 복잡도 O(n), 추가 공간 복잡도 O(1)로 실행됩니다.
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        const int n = nums.size(); // nums 벡터의 크기를 n에 저장합니다.
        int left = 0; // 왼쪽 요소들의 누적 합을 나타내는 변수를 초기화합니다.
        int right = accumulate(nums.begin(), nums.end(), 0); // 모든 nums 요소들의 합을 right에 저장합니다.
        vector<int> result(n); // 결과를 저장할 벡터를 nums와 동일한 크기로 초기화합니다.
        
        // nums 벡터를 순회하면서 각 요소에 대한 계산을 수행합니다.
        for (int i = 0; i < n; i++) {
            // result[i]에는 nums[i]와 다른 모든 요소들과의 절대 차이의 합을 계산하여 저장합니다.
            // (nums[i] * i - left)는 nums[i]보다 작은 인덱스에 있는 모든 요소들과의 차이의 합입니다.
            // (right - nums[i] * (n - i))는 nums[i]보다 큰 인덱스에 있는 모든 요소들과의 차이의 합입니다.
            result[i] = (nums[i] * i - left) + (right - nums[i] * (n - i));
            
            // 다음 반복을 위해 left와 right를 갱신합니다.
            left += nums[i]; // 현재 요소를 left에 더합니다.
            right -= nums[i]; // 현재 요소를 right에서 뺍니다.
        }
        
        return result; // 계산된 결과 벡터를 반환합니다.
    }
};

// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/?envType=daily-question&envId=2023-11-25
