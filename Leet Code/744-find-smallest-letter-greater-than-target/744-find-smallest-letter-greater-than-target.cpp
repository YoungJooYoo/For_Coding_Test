class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int start = 0;
        int end = letters.size() - 1;
        int mid;
        
        while (start <= end) {
            mid = start + (end -start) / 2; // or mid = (start + end) / 2;
            if (letters[mid] <= target) { // 문제가 원하는 리턴 값은 타겟보다 최소로 커야한다.
                start = mid + 1;
            }
            else { // letters[mid] > target
                end = mid -1;
            }
        }
        
        // 
        if (letters[start] > target) {  // 이진탐색으로 찾은 start인덱스의 letters값이 target보다 크다면 반환
			return letters[start];
		}
        
		return letters[0]; // 문제 조건에 따라, 없다면 배열의 맨 앞을 반환
    }
};