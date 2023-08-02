class Solution {
public:
    string reformatNumber(string number) {
        const size_t number_length = number.size();
        string nums;
        size_t nums_length = 0;
        int count = 0;
        string ans;
        
        for (size_t i = 0; i < number_length; i++) {
            if (number[i] >= '0' && number[i] <= '9') {
                nums_length++;
                nums.push_back(number[i]);
            }  
        } // 순수 숫자만 있을때 길이 구하고, 숫자만 넣은 배열 채우기
        
        if (nums_length == 4) {
            for (size_t i = 0; i < nums_length; i++) {
                ans.push_back(nums[i]);
                if (i == 1) ans.push_back('-');
            }
            return ans;
        } // 전화번호 길이가 4인 경우
        
        for (size_t i = 0; i < nums_length; i++) {
            ans.push_back(nums[i]);
            count++;
            if (count == 3 && i != nums_length - 1) {
                ans.push_back('-');
                count = count - 3;
            } // 전화번호 처음 3자리에 - 붙이기
            if ((nums_length % 3 == 1) && (i + 4 == nums_length - 1)) {
                ans.push_back(nums[i + 1]);
                ans.push_back(nums[i + 2]);
                ans.push_back('-');
                ans.push_back(nums[i + 3]);
                ans.push_back(nums[i + 4]);
                return ans; // 마지막에 번호가 4자리 남은 경우, 11 - 22 표기 되게
            }
        }
        
        return ans;
    }
};