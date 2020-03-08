/* 백준 10481 나이순 정렬 */
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

typedef struct people_info {
    int age;
    string name;
} people_info_t;

/* 많은 배열을 함수내부에 선언하면 스택오버플로우가 생길 수 있으니 전역변수로 선언 */
people_info_t people_info[100000 + 1];

bool compare(people_info_t src, people_info_t des) {
    return src.age < des.age;
}

int main(void)
{
    size_t n;
    size_t i;
    
    cin >> n;
    
    for (i = 0; i < n; i++) {
        cin >> people_info[i].age >> people_info[i].name;
    }
    
    /* 같은 값이면 순서를 유지시켜주는 sort */
    stable_sort(people_info, people_info + n, compare);
    
    /* endl; 사용하니 시간초과, 개행문자 "\n" */
    for (i = 0; i < n; i++) {
        cout << people_info[i].age << " " << people_info[i].name << "\n";
    }
    
    return 0;
}
