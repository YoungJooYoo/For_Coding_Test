/* Baekjoon 1316 그룹단어체커 */

#include <iostream>
#include <string>

using namespace std;

int g_words_count = 0;

/* 문자열의 단어를 조건문으로 비교해, 그룹단어라 판단되면 카운트를 안하고, 그룹단어가 아니면 카운트를 올린다. */
void get_groupwords_count(string str)
{
    int string_length = str.size();
    
    for (int i = 0; i < string_length - 2; i++) {
        if (str[i] != str[i + 1]) {
            for (int j = i + 2; j < string_length; j++) {
                if (str[j] == str[i]) {
                    return;
                } /* end if */
            } /* end for */
        } /* end if */
    } /* end for */
    g_words_count++;
}

int main(void)
{
    string str;
    size_t n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> str;
        get_groupwords_count(str);
    }

    cout << g_words_count << endl;
    
    return 0;
}
