class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) 
    {
        int freq[10] = {0, }; // to store frequency of each digit
        vector<int> outVector; // to return

        for (const int digit: digits) {
            ++freq[digit];
        }
        
        for (int num = 100; num < 999; num += 2) { // 짝수만 건너 뛰기
            int ones = num % 10;
            int tens = (num / 10) % 10;
            int hundreds = (num / 100);
            
            // checking if required number of each digit is there or not
            freq[ones]--;
            freq[tens]--;
            freq[hundreds]--;
            
            if (freq[ones] >= 0 && freq[tens] >= 0 && freq[hundreds] >= 0) outVector.push_back(num);
            
            // Undo the subtractions done earlier
            freq[ones]++;
            freq[tens]++;
            freq[hundreds]++;
            
        }
        
        return outVector;
    }
};

// https://leetcode.com/problems/finding-3-digit-even-numbers/description/
