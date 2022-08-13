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
*/