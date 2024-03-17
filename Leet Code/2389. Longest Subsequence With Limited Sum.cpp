class Solution {
public:
    std::vector<int> answerQueries(const std::vector<int>& nums, const std::vector<int>& queries) const 
    {
        std::vector<int> sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());

        // 누적 합 계산
        for (int i = 1; i < sorted_nums.size(); ++i) {
            sorted_nums[i] += sorted_nums[i - 1];
        }

        std::vector<int> ans;
        for (const auto query : queries) {
            const int ind = std::upper_bound(sorted_nums.begin(), sorted_nums.end(), query) - sorted_nums.begin(); // 이진 탐색을 사용하여 it보다 큰 값 중 첫 번째 인덱스 찾기
            ans.push_back(ind);
        }

        return ans;
    }
};

// https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/
