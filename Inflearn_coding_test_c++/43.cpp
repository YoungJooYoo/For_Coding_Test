#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int number[1001];
size_t n;

size_t count_recording_size(size_t size)
{
    size_t i;
    size_t cnt = 1;
    size_t sum = 0;
    
    for(i = 1; i <= n; i++) {
        if(sum + number[i] > size) {
            cnt++; // dvd 추가해 의미
            sum = number[i];  // 지금 이 곡부터 새로운 곡으로 시작
        }
        else sum = sum + number[i];
    }
    
    return cnt;
}

int main(void)
{
    size_t m;
    size_t i;
    size_t lt = 1; // 가장 처음
    size_t rt = 0; // 가장 마지막
    size_t mid;
    size_t res;
    int max = -2147000000;
    
    cin >> n >> m;
    
    /* 이분 검색 준비 */
    for(i = 1; i <= n; i++){
        scanf("%d", &number[i]);
        rt = rt + number[i]; //
        if(number[i] > max) {
            max = number[i];
        }
    }
    
    /* 이분 검색 */
    while(lt <= rt){
        mid = (lt + rt) / 2; // 처음과 마지막으로 반나누어 중간을 구함
        if(mid >= max && count_recording_size(mid) <= m){
            res = mid; // 2분 검색으로 출력할 값을 찾는다.
            rt = mid - 1;
        }
        else {
            lt = mid + 1;
        }
    }
    
    cout << res << endl;
    
    return 0;
}
