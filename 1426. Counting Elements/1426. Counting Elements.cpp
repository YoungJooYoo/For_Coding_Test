class Solution {
public:
    int countElements(vector<int>& arr) 
    {
        auto nums = unordered_set<int>(arr.begin(), arr.end()); // 배열에 중복제거
        int count = 0;

        /*
        for (const auto& num : nums ) {
            if (nums.find(num + 1) != nums.end()) {
                ++count;
            }
        }
        */

        for (int i = 0; i < arr.size(); ++i) {
            if (nums.find(arr[i] + 1) != nums.end()) {
                ++count;
            }
        }
        return count;

        //return count_if(as.begin(), as.end(), [&](auto a) { return exist.count(a + 1); });
    }
};

// https://leetcode.com/problems/counting-elements/description/
