class Solution {
public:
    int numDifferentIntegers(const string word) 
    {
        unordered_set<string> nums;
        const size_t LEN = word.size();
        string temp = "";

        for (size_t i = 0; i < LEN; ++i) {
            if ('0' <= word[i] and word[i] <= '9') {
                string temp;
                while (word[i] == '0') ++i; // 앞에 숫자가 0이면 넘겨버림
                while (isdigit(word[i]) == true) temp += word[i++];
                nums.insert(temp);
            }
        }
         
        return nums.size();    
    }
};
