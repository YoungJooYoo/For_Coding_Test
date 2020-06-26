#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

size_t n;
size_t x[200000 + 1]; // 동적배열 선언

size_t count_stable_size(size_t len, size_t x[])
{
    size_t i;
    size_t cnt = 1;
    size_t pos = x[1];
    
    for(i = 2; i <= n; i++){
        if(x[i] - pos >= len){
            cnt++;
            pos = x[i];
        }
    }
    
    return cnt;
}

int main(void){
    
    size_t m;
    size_t i;
    size_t lt = 1;
    size_t rt;
    size_t mid;
    size_t res = 0;
    
    cin >> n >> m;
    
    for(i=1; i<=n; i++){
        cin >> x[i];
    }
    
    sort(x + 1, x + n + 1);
    
    rt = x[n];
    
    while(lt <= rt){
        mid = (lt + rt) / 2;
        
        if(count_stable_size(mid, x) >= m){
            res = mid;
            lt = mid+1;
        }
        else {
          rt = mid-1;
        }
    }
    
    cout << res << endl;
    return 0;
}
