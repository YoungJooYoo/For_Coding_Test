class Solution {
public:
    int maximum69Number (int num) 
    {
        // 배열에 담아서 뒤에서 6->9로 바꾼다.
        vector<int> nums;

        while (num != 0) {
            nums.push_back(num % 10);
            num /= 10;
        }
        reverse(nums.begin(), nums.end());

        for (auto& number : nums) {
            if (number == 6) {
                number = 9;
                break;
            }
        }

        for (const auto& number : nums) {
            num += number;
            num *= 10;
        }
        num /= 10;

        return num;        
    }
};

// https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/description/
