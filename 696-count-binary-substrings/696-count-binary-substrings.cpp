class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        vector<int> groups;
        int count = 1;
        
        for (size_t i = 1; i <= s.size(); i++) {
            if (s[i] != s[i - 1]) {
                groups.push_back(count);
                count = 1;
            } 
            else
                count++;
        }

        int res = 0;
        
        for (size_t i = 1; i < groups.size(); i++) {
            res += min(groups[i - 1], groups[i]);
        }

        return res;
    }
};

/*
풀이법 :
DP
패턴에 따라 나온는 substrings의 개수가 패턴이 있다.
이 패턴을 따라서, 작게 나오는 값을 이용한다

 0011
In this string, consecutive count of binary characters are [2, 2]. We can form a total of 2 substrings.

2. 00011
In this string, consecutive count of binary characters are [3, 2]. Still, we can only form 2 substrings.

3. 000111
Here, consecutive count of binary characters are as - [3,3]. Now, we can form 3 substrings.

4. 00011100
Consecutive count of binary characters are - [3,3,2]. We can form 3 substrings with the first 2 groups of zeros and ones. 
Then we can form 2 substrings with the latter 2 groups. So, a total of 5 substrings.

5. 00011100111
Consecutive count - [3,3,2,3]. Substrings formed - 3 + 2 + 2 = 7


*/