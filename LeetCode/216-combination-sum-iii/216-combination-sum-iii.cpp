class Solution 
{
public:
    void recursive(int k, int n, int index)
    {
        if (temp.size() == k && n == 0) {
            result.push_back(temp);
            return;
        }
        
        for (int i = index; i < MAX; i++) {
            temp.push_back(i);
            recursive(k, n - i, i + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        recursive(k, n, 1); // k, n, 1부터 시작
        return result;
    }
    
private:
    vector<vector<int>> result;
    vector<int> temp;
    enum { MAX = 10 };
};

/*

풀이법 :

처음 구할때 시간초과 발생
temp의 배열을 구하고, 내부를 다 더해서, 조건에 부합하는지 계속 체크를 했고,
이 부분이 시간초과를 유발한 듯 하다.

이를 개선해 for문에서 다시 재귀를 구할때 sum을 이미 구할 수 있는 방법
즉, n에다 값을 변경해가며 찾아가는 방식으로
temp배열을 다시 찾아야하는 번거러움을 줄였다.


재귀라서, 직접 출력해보면서 원소 변화를 보는게 좋다.
반복문에 재귀를 쓴 것이라, 중복 값이 들어가는 경우가 있을 수 있는데
이를 주의해야하므로, 중복되는 원소를 제거해야한다.
특히 재귀호출하는 동시에 for문 탐색으로 재귀를 또 호출하면서
중복값들이 들어가는데, 이를 처리하기 위한 조건이 매우 중요하다.

간단하게 재귀를 호출하면서 n값을 바꾸면 중복 값이 들어올 수 없는 구조가 된다.

*/