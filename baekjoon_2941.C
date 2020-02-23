// 백준 2941 크로아티아 알파벳
// 일반 알파벳 + 크로아티아 알파벳을 카운팅하는 것

#include <stdio.h>
#define STRING_LENGTH (100 + 1)
#define NEXT_POS (1)

size_t get_croatia_alphabet_length(char* string) {
    
    size_t count = 0;
    size_t i = 0;
   
    /* 문자열의 끝은 '\0'이므로 문자열 끝까지 탐색 */
   for (i = 0; string[i] != '\0'; i++) {
        if (string[i] == 'n' || string[i] == 'l') {
            if (string[i + NEXT_POS] == 'j') continue;
        } else if (string[i] == 'c' || string[i] == 's' || string[i] == 'z') {
            if (string[i + NEXT_POS] == '=' || string[i + NEXT_POS] == '-') continue;
        } else if (string[i] == 'd') {
            if (string[i + NEXT_POS] == '-') continue;
            if (string[i + NEXT_POS] == 'z' && string[i + NEXT_POS + NEXT_POS] == '=') continue;
        }
       count++;
    }

    return count;
}

int main(void) {
    
    char string[STRING_LENGTH];
    
    scanf("%s", string);
    printf("%lu\n", get_croatia_alphabet_length(string));
    
    return 0;
}
