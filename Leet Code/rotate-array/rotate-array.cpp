class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const size_t nums_length = nums.size();
        vector<int> ans;
        size_t i;
   
        for (i = 0; i < nums_length - (k % nums_length); i++) {
            nums.push_back(nums[i]);
        }
        nums.erase(nums.begin(), nums.begin() + i);
    }
};

/*

풀이법 :     
nums_length - (k % nums_length) => ex) k가 10이고, nums 길이가 7이라면
한바퀴 도는 주기가 7번, 움직인 효과가 나려면 1 ~ 6번 움직여야함 따라서, k가 얼마나 크던 1~6까지 나오게 연산 후, 나온 값만 움직이려고 연산한다
erase함수를 통해, 앞의 값들을 지운다.

*/