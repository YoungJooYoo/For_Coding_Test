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
    stack<char> input_stack;
    string input;
    int flag = 1;

    cin >> input;

    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
        {
            input_stack.push(input[i]);
        }
        else
        {
            if (input_stack.empty())
            {
                cout << "NO" << endl;
                flag = 0; // (()))( 이런 상황에서 ) ( 순서 때문에 잘못되는 것을 방지하기 위한 flag
                return 0;
            }
            else
            {
                input_stack.pop();
            }
        }
    }
    
    if (input_stack.empty() && flag == 1)  // flag 1이 정상종료
    {
        cout << "YES" << endl;
        return 0;
    }
    else if (!input_stack.empty() && flag == 1)
    {
        cout << "NO" << endl;
        return 0;
    }

    return 0;
} 
