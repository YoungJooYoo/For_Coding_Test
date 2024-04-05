class Solution {
public:
    int divisorSubstrings(const int num, const int k) 
    {
        const string NUMBER = to_string(num);
        const size_t STR_LEGNTH = NUMBER.size();
        int count = 0;

        for (size_t i = 0; i <= STR_LEGNTH - k; ++i) {
            const string SUB = NUMBER.substr(i, k);
            const int value = stoi(SUB);
            if (value != 0 && num % value == 0) ++count;
        }

        return count;
    }
};

// https://leetcode.com/problems/find-the-k-beauty-of-a-number/description/

/*
주어진 정수 `num`의 k-뷰티는 다음 조건을 충족하는 문자열로 읽었을 때의 부분 문자열의 수입니다:

1. 길이가 k여야 합니다.
2. num의 약수여야 합니다.

정수 num과 k가 주어졌을 때, num의 k-뷰티를 반환합니다.

**예시**

입력: num = 240, k = 2  
출력: 2  
설명: 다음은 길이가 k인 num의 부분 문자열입니다:
- "24" from "240": 24는 240의 약수입니다.
- "40" from "240": 40은 240의 약수입니다.
따라서 k-뷰티는 2입니다.

입력: num = 430043, k = 2  
출력: 2  
설명: 다음은 길이가 k인 num의 부분 문자열입니다:
- "43" from "430043": 43은 430043의 약수입니다.
- "30" from "430043": 30은 430043의 약수가 아닙니다.
- "00" from "430043": 0은 430043의 약수가 아닙니다.
- "04" from "430043": 4는 430043의 약수가 아닙니다.
- "43" from "430043": 43은 430043의 약수입니다.
따라서 k-뷰티는 2입니다.


주어진 숫자 `num`을 문자열로 변환했을 때, 이 문자열에서 길이가 `k`인 부분 문자열 중에서 `num`의 약수인 것의 개수를 구하는 문제야.

예를 들어, `num`이 240이고 `k`가 2일 때, 문자열로 변환하면 "240"가 되겠지? 여기서 길이가 2인 부분 문자열은 "24", "40"이 되는데, 이 중에서 240의 약수인 것은 "24"와 "40"이야. 그래서 결과적으로 2를 반환하면 돼.

*/
