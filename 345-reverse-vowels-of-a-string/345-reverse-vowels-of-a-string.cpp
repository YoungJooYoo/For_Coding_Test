class Solution {
private:
bool is_vowels(char c)
    {
        return (c=='a' or c=='e' or c=='i' or c=='o' or c=='u') ? true : false; 
    }

public:
    string reverseVowels(string s) 
    {
            int left = 0; 
            int right = s.size() - 1;

        while(left <= right) {
            bool char1 = is_vowels(tolower(s[left]));
            bool char2 = is_vowels(tolower(s[right]));

            if(char1 == true and char2 == true) {
                swap(s[left], s[right]);
                left++; 
                right--;
            }
            else if (char1 == true and char2 == false) {
                right--;
            }
            else if (char1 == false and char2 == true) {
                left++;
            }
            else {
                left++;
                right--;
            }

        }

        return s;
    }
};