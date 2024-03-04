class Solution {
public:
    vector<int> resultArray(const vector<int>& nums) 
    {
        vector<int> arr1, arr2; // 두 배열 초기화
        
        // 첫 번째 요소를 arr1에, 두 번째 요소를 arr2에 추가
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        
        // 세 번째 요소부터 시작하여 규칙에 따라 분배
        for (size_t i = 2; i < nums.size(); ++i) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        
        // arr1과 arr2를 연결하여 결과 배열 생성
        vector<int> result(arr1.begin(), arr1.end());
        result.insert(result.end(), arr2.begin(), arr2.end());
        
        return result;
    }
};

// https://leetcode.com/problems/distribute-elements-into-two-arrays-i/description/
