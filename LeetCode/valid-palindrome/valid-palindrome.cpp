class Solution {
public:
   bool isPalindrome(string s) 
   {
        int left = 0; 
        int right = s.size() - 1;
       
        while(left < right)  {
            if (isalnum(s[left]) == false)  {
                left++;
            }
            else if (isalnum(s[right]) == false) {
                right--;
            }
            else  {
                if (tolower(s[left++]) != tolower(s[right--])) {
                    return false;
                }
            }
        }
       
        return true;
    }
};