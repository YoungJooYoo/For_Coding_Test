class Solution {
public:
    int findMinimumOperations(string& s1, string& s2, string& s3) 
    {
        const int LEN1 = s1.size();
        const int LEN2 = s2.size();
        const int LEN3 = s3.size();
        
        int count = 0;

        int MIN_LEN = min(LEN1, LEN2);
        MIN_LEN = min(MIN_LEN, LEN3);


        for (size_t i = 0; i  < MIN_LEN; ++i){
            if (s1[i] == s2[i] && s2[i] == s3[i]) ++count;
            else break;
        }

        if (count == 0) {
            return FAIL;
        }

        const int TOTAL_LENGTH = LEN1 + LEN2 + LEN3;
        const int COUNT_LENGTH = 3 * count;
        return TOTAL_LENGTH - COUNT_LENGTH;
    }

private:
    enum { FAIL = -1 };
};

//  https://leetcode.com/problems/make-three-strings-equal/description/
