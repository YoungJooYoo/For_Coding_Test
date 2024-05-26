class Solution {
public:
    int numberOfPairs(const vector<int>& nums1, vector<int>& nums2, const int k) 
    {
        int result = 0;

        for (int& num : nums2)
        {
            num *= k;
        }

        for (const auto& num1 : nums1)
        {
            for (const auto& num2 :nums2)
            {
                if (num1 % num2 == 0)
                {
                    ++result;
                }
            }
        }

        return result;
    }
};


/*
이 문제는 두 정수 배열 `nums1`과 `nums2`가 주어졌을 때, 
주어진 양의 정수 `k`에 대해 `nums1[i]`가 `nums2[j] * k`로 나눠 떨어지는 경우의 쌍 `(i, j)`의 수를 구하는 것입니다. 

예를 들어, 배열 `nums1 = [1, 3, 4]`과 `nums2 = [1, 3, 4]`가 주어지고 `k = 1`인 경우, 
`nums1[i]`가 `nums2[j] * k`로 나눠 떨어지는 `(i, j)` 쌍은 `(0, 0)`, `(1, 0)`, `(1, 1)`, `(2, 0)`, `(2, 2)`입니다. 
총 5개의 쌍이 존재합니다.

이 문제를 해결하기 위해 두 중첩 루프를 사용하여 각 `nums1[i]`와 `nums2[j] * k`를 비교하고, 
조건을 만족하는 경우의 수를 세어줍니다.


*/

// https://leetcode.com/problems/find-the-number-of-good-pairs-i/
