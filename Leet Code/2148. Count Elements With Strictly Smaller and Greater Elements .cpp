class Solution {
public:
    int countElements(const vector<int>& nums) 
    {
        map<int, int> freq; // std::map 사용

        for (const int num : nums) {
            ++freq[num]; // 빈도수 업데이트
        }

        if (freq.size() <= 2) {
            return 0;
        }

        // std::map의 첫 번째 요소의 빈도와 마지막 요소의 빈도를 찾음
        const int minFreq = freq.begin()->second;
        const int maxFreq = prev(freq.end())->second; // prev 함수로 마지막 요소 접근

        return nums.size() - (minFreq + maxFreq);
    }
};

// https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
