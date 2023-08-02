class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        const size_t arr_length = arr.size();
        
        // 배열의 마지막 인덱스에 있는 값의 정수 만큼 반복문 돌린다.
        for (size_t i = 1, j = 0; i < arr[arr_length - 1]; i++) { // 정수 1부터 존재하는지 체크, 인덱스 0은 1부터 시작
            if (arr[j] == i) {
                j++;
            }
            else { // 존재하지 않으면 k감소
                k--;
            }
            if (k == 0) {
                return i;
            }
        }
            
        return arr[arr_length - 1] + k; // 배열의 마지막 정수에 k만큼 더해서 리턴
    } 
};