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
                return 0;
            }
            else
            {
                input_stack.pop();
            }
        }
    }
    
    if (input_stack.empty())
    {
        cout << "YES" << endl;
        return 0;
    }
    else
    {
        cout << "NO" << endl;
        return 0;
    }

    return 0;
} 
