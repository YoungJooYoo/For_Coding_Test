class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int start = 0;
        int end = letters.size() - 1;
        int mid;
        
        while (start <= end) {
            mid = start + (end -start) / 2; // or mid = (start + end) / 2;
            if (letters[mid] <= target) {
                start = mid + 1;
            }
            else { // letters[mid] > target
                end = mid -1;
            }
        }
        
        if (letters[start] > target){
			return letters[start];
		}
        
		return letters[0];
    }
};