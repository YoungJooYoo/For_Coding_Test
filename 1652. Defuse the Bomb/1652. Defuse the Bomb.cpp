class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        vector<int> result(code.size(), 0);
        const size_t SIZE = code.size();

        for(int i = 0; i < SIZE; ++i) { 
            if (k > 0){ // 앞으로 이동
                int sum = 0;
                for (int j = 1; j <= k; ++j) {
                    int index = i + j;
                    index %= SIZE;
                    sum += code[index];
                }
                result[i] = sum;
            }
            else if (k < 0) { // 뒤로 이동
                int sum = 0;
                for (int count = -1; count >= k; --count) { 
                    int index = i + count;
                    if (index < 0){
                        index += SIZE;
                    }
                    sum += code[index];
                }
                result[i] = sum;
            }
        }

        return result;
    }
};

// https://leetcode.com/problems/defuse-the-bomb/description/
