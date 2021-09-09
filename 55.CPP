#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>

#define ARRAY_LENGTH (sizeof(arr) / sizeof(arr[0]))

using namespace std;


int main(void) 
{
    //freopen("input.txt", "rt", stdin);
    size_t n;
    size_t m;
    size_t i;
    size_t j = 1;
    stack<size_t> intersection;
    vector<char> str;
    
    cin >> n;
    vector<size_t> b_city(n + 1);

    // 도착순서 배열, 스택 뺴면서 이 배열과 비교하면서 순서가 일치하는지 확인
    for (size_t i = 1; i <= n; i++)
    {
        b_city[i] = i;
    }
    
    for (i = 1; i <= n; i++)
    {
        cin >> m;
        intersection.push(m);
        str.push_back('P');

        while (true) 
        {
            if (intersection.empty() == true)
            {
                break;
            }

            if (b_city[j] == intersection.top())
            {
                intersection.pop();
                str.push_back('O');
                j++;
            }
            else
            {
                break;
            }
        }
    }

    if (!intersection.empty())
    {
        cout << "impossible" << endl;
    }
    else
    {
        for (i = 0; i < str.size(); i++)
        {
            cout << str[i] << endl;
        }
    }

    return 0;
} 
