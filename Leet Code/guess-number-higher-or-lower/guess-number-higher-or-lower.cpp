class Solution {
public:
    int guessNumber(int n) 
    {
        int start = 1;
        int mid;
        int end = n;
        int guess_val;
        
        while(start <= end) {
            mid = start + (end - start) / 2;
            guess_val = guess(mid);
            if(guess_val == 0) {
                return mid;    
            }
            else if(guess_val == 1) {
                start = mid + 1;
            }
            else  { // ans = -1
                end = mid ;
            }
        }
        
        return 0;
    }
};