class Solution {
public:
    vector<int> distinctDifferenceArray(const vector<int>& nums) 
    {
        const size_t LEN = nums.size();

        unordered_set<int> prefix;
        unordered_set<int> suffix;
        
        vector<int> result(LEN, 0);
        vector<int> suffix_count(LEN, 0); // 각 인덱스에서 접미사의 고유 원소 수를 저장

        // 접미사의 고유 원소 수 계산
        for (int i = LEN - 1; i >= 0; --i) {
            suffix.insert(nums[i]);
            suffix_count[i] = suffix.size();
        }

        // 접두사의 고유 원소 수를 사용하여 최종 결과 계산
        for (int i = 0; i < LEN; ++i) {
            prefix.insert(nums[i]);
            result[i] = prefix.size() - (i < LEN - 1 ? suffix_count[i + 1] : 0);
        }
        /*
            배열을 처음부터 순회하며 접두사의 고유 원소를 추가하고, 
            현재 인덱스에서 접미사의 고유 원소 수(suffix_count[i + 1])를 차감하여 결과를 계산합니다. 
            배열의 마지막 원소에 대해서는 접미사가 존재하지 않으므로, 접미사의 원소 수를 0으로 간주합니다.
        */

        return result;
    }
};

// https://leetcode.com/problems/find-the-distinct-difference-array/description/
