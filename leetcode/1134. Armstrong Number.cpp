class Solution {
public:
    bool isArmstrong(int n) 
    {
        const string number = to_string(n);
        int sum = 0;

        for (const auto& num : number) {
            sum += pow(num - '0', number.size());
        }

        return sum == n ? true : false;
    }
};


// https://leetcode.com/problems/armstrong-number/description/
