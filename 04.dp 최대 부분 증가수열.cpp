#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>

using namespace std;
#define ARRAY_LENGTH (sizeof(direction) / sizeof(direction[0]))

// 내가 만들려는 수열의 가장 긴 길이를 저장하는 배열  
// ex) memoization[3], 3번째까지 항중에서 가장 긴 수열 길이 저장
size_t memoization[50000]; 
size_t nums[50000];

// dp로 물제풀이
int main(void) 
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "rt", stdin);

    size_t n;
    int max;
    int res = 0;

    cin >> n;
    for (size_t i = 1; i <= n; i++) // 인덱스 1부터 시작
    {
         cin >> nums[i];
    }
    
    memoization[1] = 1; // 1번쨰 원소의 수열은 길이가 1

    for (size_t i = 2; i <= n; i++) // 배열의 2번쨰 원소부터 수열 길이 구하기 시작
    {
        max = 0;
        for (int j = i - 1; j >= 1; j--) // 배열에서 인덱스 i보다 앞에 놓인 위치에서 수열길이 검색
        {
            if (nums[j] < nums[i] && memoization[j] > max)  // max보다 크고, 인덱스 i보다 작은 원소만
            {
                max = memoization[j];
            }
        }
        memoization[i] = max + 1; // 조건에 일치하면 길이가 차츰 증가
        if (memoization[i] > res) // 최대값 찾기
        {
            res = memoization[i];
        }
    }

    cout << res << endl;
    return 0;
} 
