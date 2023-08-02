class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) 
    {
        vector<int> result;
        
        while (left <= right) {
            int temp = left;
            bool divide_flag = true;
            while (temp != 0) {
                int op = temp % 10;
                if (op == 0) {
                    divide_flag = false;
                    break;
                }
                if (op != 0) {
                    if (left % op != 0) {
                        divide_flag = false;
                        break;
                    }
                }
                temp /= 10;
            }
            if (divide_flag == true) result.push_back(left);
            ++left;
        }

        return result;        
    }
};

https://leetcode.com/problems/self-dividing-numbers/description/
