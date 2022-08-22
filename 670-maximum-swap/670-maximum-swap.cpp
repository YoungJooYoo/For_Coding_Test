class Solution {
public:
    int maximumSwap(int num) 
    {
        string str_num = to_string(num);
        int size = str_num.size();
        int result = num;
        
        for (size_t i = 0; i < size - 1; i++) {
            for (size_t j = i + 1; j < size; j++) {
                swap(str_num[i], str_num[j]);
                int temp = stoi(str_num);
                result = max(result, temp); // 최대값 찾기
                swap(str_num[i], str_num[j]); // 바꾼 숫자 원복하기
            }
        }
        
        return result;
    }
};