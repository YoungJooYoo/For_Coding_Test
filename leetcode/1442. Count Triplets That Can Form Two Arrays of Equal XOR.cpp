class Solution 
{
public:
    int countTriplets(const vector<int>& arr) 
    {
        const size_t ARRAY_LENGTH = arr.size();
        int count = 0;
        vector<int> xorSum(ARRAY_LENGTH + 1, 0);

        for (size_t i = 0; i < ARRAY_LENGTH; ++i)
        {
            xorSum[i + 1] = xorSum[i] ^ arr[i];
        }

        for (int i = 0; i < ARRAY_LENGTH; i++) 
        {
            for (int j = i + 1; j < ARRAY_LENGTH + 1; j++) 
            {
                if (xorSum[i] == xorSum[j]) 
                {
                    count += (j - i - 1); // i < j <= k 조건을 만족하는 k의 개수
                }
            }
        }

        return count;
    }
};

// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/

/*
문제 설명
정수 배열 arr이 주어집니다.

우리는 세 개의 인덱스 i, j, k를 선택하고 싶습니다. 여기서 0 <= i < j <= k < arr.length 입니다.

이제 a와 b를 다음과 같이 정의합니다:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
여기서 ^는 비트 연산자 XOR을 나타냅니다.

a == b가 성립하는 트리플렛 (i, j, k)의 개수를 반환하세요.

예시
예시 1:

입력: arr = [2,3,1,6,7]
출력: 4
설명: 가능한 트리플렛은 (0,1,2), (0,2,2), (2,3,4), (2,4,4)입니다.
예시 2:

입력: arr = [1,1,1,1,1]
출력: 10
제약 조건
1 <= arr.length <= 300
1 <= arr[i] <= 10^8

문제 풀이 절차
1. XOR 연산의 특성 이해:
XOR은 다음과 같은 성질을 가집니다:

x ^ x = 0: 같은 숫자를 XOR하면 결과는 0이 됩니다.
x ^ 0 = x: 0과 XOR하면 원래 숫자가 나옵니다.
이 특성을 활용하면, 만약 a == b라는 조건을 만족시키려면 배열의 특정 범위에서 XOR 값이 0이 되어야 합니다. 즉, arr[i] ^ arr[i+1] ^ ... ^ arr[k] == 0인 경우가 우리가 찾고자 하는 (i, j, k) 트리플릿을 나타냅니다.

2. 누적 XOR 값을 계산:
이 문제는 arr 배열의 부분 XOR 값을 구하는 문제로 바꿀 수 있습니다. 먼저 배열의 누적 XOR 값을 계산합니다. 누적 XOR 값은 배열의 앞에서부터 특정 인덱스까지의 XOR 값을 저장한 배열입니다.

예를 들어, 누적 XOR 배열 xorSum[i]는 arr[0]부터 arr[i-1]까지의 XOR 값을 나타냅니다. 그러므로 두 인덱스 i와 j에 대해 xorSum[i] == xorSum[j]라면, arr[i]부터 arr[j-1]까지의 XOR 값이 0이라는 의미가 됩니다.
풀이 과정:
xorSum[i]는 arr[0]부터 arr[i-1]까지의 XOR 값을 저장하는 누적 XOR 배열입니다.
예를 들어, xorSum[3]은 arr[0] ^ arr[1] ^ arr[2] 값을 나타냅니다.
두 인덱스 i와 j에 대해 xorSum[i] == xorSum[j]이면, 그 사이의 XOR 값이 0이라는 뜻입니다. 즉, arr[i]부터 arr[j-1]까지의 XOR 결과가 0이므로 이 구간에서 조건을 만족하는 트리플릿이 존재합니다.
j - i - 1은 트리플릿 (i, j, k)에서 가능한 k의 개수입니다. 즉, k는 j부터 n까지의 범위에서 선택될 수 있습니다.
결론:
이 알고리즘은 각 구간의 XOR 값을 누적 XOR을 통해 계산하여, xorSum[i] == xorSum[j]인 구간을 찾아 트리플릿의 개수를 계산하는 방식입니다. 이를 통해 O(n^2) 시간 복잡도로 문제를 해결할 수 있습니다.

*/
