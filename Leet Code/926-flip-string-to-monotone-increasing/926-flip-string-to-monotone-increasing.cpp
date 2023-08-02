class Solution {
public:
    int minFlipsMonoIncr(const std::string& S) 
    {
        int counter_one  = 0; 
        int counter_flip = 0;
        
        // 1을 0으로 바꿀지 0을 1로 바꿀지 고른다.
        for (const auto& ch : S) {
            if (ch == '1') {
                ++counter_one; // example 3번 참조, 1을 전부 0으로 바꾸는 경우
            } else {
                ++counter_flip; // 0을 1로 바꾸는 경우
            }
            counter_flip = min(counter_one, counter_flip);
        }
        
        return counter_flip;
    }
};