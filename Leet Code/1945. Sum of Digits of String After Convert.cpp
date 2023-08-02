class Solution {
public:
    int getLucky(string s, int k) 
    {
        string num = "";
        int sum = 0;

        for (const auto& ch : s) {
            char temp = ch - ('a' - 1); // a = 97, - 1 = 96
            num += to_string(temp);
        }

        while (k-- != 0) {
            for (const auto& number : num) {
                sum += number - '0';
            }

            num = to_string(sum);
            sum = 0;
        }

        return stoi(num);    
    }
};

// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/
