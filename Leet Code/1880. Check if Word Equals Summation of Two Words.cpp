class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) 
    {
        int temp1 = 0;
        for (const auto& ch : firstWord) {
            temp1 = temp1 * 10 + (ch - 'a');
        }

        int temp2 = 0;
        for (const auto& ch : secondWord) {
            temp2 = temp2 * 10 + (ch - 'a');
        }

        int temp3 = 0;
        for (const auto& ch : targetWord) {
            temp3 = (temp3 * 10) + (ch - 'a');
        }

        return temp1 + temp2 == temp3;
    }
};
