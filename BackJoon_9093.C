//  백준9093 단어뒤집기
#include <iostream>
#include <stdio.h>

using namespace std;
typedef unsigned long size_t;

/* 문자열 길이 구하는 함수 */
size_t get_string_length(const char* str)
{
    const char* p = str;
    size_t count = 0;
    
    while (*p++ != '\0') {
        count++;
    }
    
    return count;
}

void reverse_by_words(char* str)
{
    char temp = '\0';
    size_t i;
    size_t string_length = 0;
    size_t length_count = 0; /* start_index + length_count로 last index를 구할 수 있다. */
    size_t start_index = 0;  /* 단어 위치변경 배열의 첫인덱스 */
    size_t last_index = 0;   /* 단어 위치변경 배열의 마지막인덱스 */
    
    string_length = get_string_length(str);
    
    for (i = 0; i <= string_length; i++) {
        length_count++;
        if (str[i] == ' ' || str[i] == '\0') { /* 공백기준으로 탐색을 진행하고, 마지막문자는 공백이 아닌 NULL을 가기 때문에 */
            start_index = (i + 1) - length_count; /* i가 멈춘 위치 - 길이 + 1 = 시작위치 */
            last_index = start_index + length_count - 2; /* 공백위치 빼고, 배열인덱스 빼고 */
            
            while (start_index < last_index) { /* arr[1] arr[2] arr[3] arr[4]  1,4랑바꾸고 2,3이랑 바꾸면 된다. */
                temp = str[start_index];
                str[start_index++] = str[last_index];
                str[last_index--] = temp;
            }
            length_count = 0; /* 초기화 */
        }
    }
}

int main(void)
{
    size_t n;
    size_t i;
    char str[1001] = {0, };
    
    cin >> n;
    cin.ignore(); /* cin 입력버퍼를 비워준다. */
    
    for (i = 0; i < n; i++) {
        cin.getline(str, 1001); /* fgets 사용하려다 enter로 입력으로 들어가 이것을 사용 */
        reverse_by_words(str);
        cout << str << endl;
    }

    return 0;
}
