class Solution {
public:
    string digitSum(string s, int k) 
    {
        while (s.size() > k) {
            string str = "";
            int sum = 0;
            int count = 0;
            for (size_t i = 0; i < s.size(); ++i) {
                sum += s[i] - '0';
                ++count;
                if (count == k) {
                    str += to_string(sum);
                    count ^= count;
                    sum ^= sum;
                }
            }
            if (count > 0) { // k길이만큼 안나누어 떨어지는 경우도 합산
                str += to_string(sum);
            }
            s  = str;
        }

        return s;
    }
};

/*
https://leetcode.com/problems/calculate-digit-sum-of-a-string/description/
https://leetcode.com/navneetkchy/
*/
