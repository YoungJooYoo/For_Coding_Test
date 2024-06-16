class Solution 
{
public:

    int countGoodTriplets(const vector<int>& arr, const int a, const int b, const int c) 
    {
        const size_t LENGTH = arr.size();
        int result = 0;
    
        for (size_t i = 0; i < LENGTH; ++i)
        {
            for (size_t j = i + 1; j < LENGTH; ++j)
            {
                for (size_t k = j + 1; k < LENGTH; ++k)
                {
                    const int num1 =  abs(arr[i] - arr[j]);
                    const int num2 =  abs(arr[j] - arr[k]);
                    const int num3 =  abs(arr[k] - arr[i]);
                    if (num1 <= a && num2 <= b && num3 <= c)
                    {
                        ++result;
                    } 
                }
            }
        }

        return result;
    }


// https://leetcode.com/problems/count-good-triplets/description/

};

/*
1534. 좋은 삼중항의 개수
난이도: 쉬움

주제: 배열, 조건

정수 배열 arr과 세 개의 정수 a, b, c가 주어집니다. 좋은 삼중항의 개수를 찾아야 합니다.

삼중항 (arr[i], arr[j], arr[k])이 다음 조건을 만족하면 좋은 삼중항입니다:

0 <= i < j < k < arr.length
|arr[i] - arr[j]| <= a
|arr[j] - arr[k]| <= b
|arr[i] - arr[k]| <= c
여기서 |x|는 x의 절대값을 나타냅니다.

좋은 삼중항의 개수를 반환하세요.

예제 1:
입력: arr = [3, 0, 1, 1, 9, 7], a = 7, b = 2, c = 3
출력: 4
설명: 좋은 삼중항은 [(3, 0, 1), (3, 0, 1), (3, 1, 1), (0, 1, 1)] 입니다.
예제 2:
입력: arr = [1, 1, 2, 2, 3], a = 0, b = 0, c = 1
출력: 0
설명: 모든 조건을 만족하는 삼중항이 없습니다.
제약 조건:
arr.length는 3 이상 100 이하입니다.
arr[i]는 0 이상 1000 이하입니다.
a, b, c는 0 이상 1000 이하입니다.
*/
