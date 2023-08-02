#pragma warning(disable:4996)
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;
#define ARRAY_LENGTH (sizeof(direction) / sizeof(direction[0]))

int memoization[50000];

struct Brick 
{
    size_t s;
    size_t h;
    size_t w;
    
    Brick(int a, int b, int c) {
        s = a;
        h = b;
        w = c;
    }

    // 연산자 오버로딩 내림차순 정렬
    bool operator<(const Brick& b)const {
        return s > b.s;
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "rt", stdin);

    size_t n, a, b, c;
    size_t max_h = 0;
    int res = 0;
    vector<Brick> Bricks;
    
    cin >> n;
    vector<int> memoization(n, 0);
    for (size_t i = 1; i <= n; i++) 
    {
        cin >> a >> b >> c;
        Bricks.push_back(Brick(a, b, c));
    }

    sort(Bricks.begin(), Bricks.end()); // 밑면 s 에 의한 내림차순 정렬
    memoization[0] = Bricks[0].h;
    res = memoization[0];

    // 0번은 위에서 처리해서 1번부터
    for (size_t i = 1; i < n; i++)
    {
        max_h = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (Bricks[j].w > Bricks[i].w && memoization[j] > max_h) 
            {
                max_h = memoization[j];
            }
        }
        memoization[i] = max_h + Bricks[i].h;
        res = max(res, memoization[i]);
    }
  
    cout << res << endl;
    return 0;
}
