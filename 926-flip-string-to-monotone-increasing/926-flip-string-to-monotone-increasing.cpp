class Solution {
public:
    int minFlipsMonoIncr(const std::string& S) 
    {
        int counter_one  = 0; 
        int counter_flip = 0;
        
        for (const auto& ch : S) {
            if (ch == '1') {
                ++counter_one;
            } else {
                ++counter_flip;
            }
            counter_flip = min(counter_one, counter_flip);
        }
        
        return counter_flip;
    }
};