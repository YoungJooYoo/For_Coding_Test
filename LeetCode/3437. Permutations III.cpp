class Solution 
{
public:
    vector<vector<int>> permute(const int n) 
    {
        assert(n >= MIN_N && n <= MAX_N);

        for (int i = 1; i <= n; ++i)
        {
            vector<int> temp;
            temp.push_back(i);
            permuteHelperRecurisve(n, temp);
        }
        
        sort(mResult.begin(), mResult.end());
        return mResult;
    }

private:
    void permuteHelperRecurisve(const int n, vector<int>& temp)
    {
        if (temp.size() == n)
        {
            mResult.push_back(temp);
            return;
        }
        
        for (int candidate = 1; candidate <= n; ++candidate)
        {
            const int last = temp.back(); 
            if (find(temp.begin(), temp.end(), candidate) == temp.end() && (last % 2) != (candidate % 2)) // 중복 및 홀짝 검사
            {
                temp.push_back(candidate);
                permuteHelperRecurisve(n, temp);
                temp.pop_back();
            }
        }
    }

private:
    vector<vector<int>> mResult;

    enum 
    { 
        MIN_N = 1, 
        MAX_N = 10 
    };
};

// https://leetcode.com/problems/permutations-iii/description/

/*
문제 번역
3437. 교대 순열
Medium

문제 설명:
정수 n이 주어지면, 교대 순열(alternating permutation)은 1부터 n까지의 양의 정수로 구성된 순열 중에서, 인접한 두 원소가 모두 홀수이거나 모두 짝수가 아닌 순열을 의미합니다.

조건을 만족하는 모든 교대 순열을 사전 순(lexicographical order)으로 정렬하여 반환하세요.

예제 1:

입력: n = 4
출력: [[1,2,3,4], [1,4,3,2], [2,1,4,3], [2,3,4,1], [3,2,1,4], [3,4,1,2], [4,1,2,3], [4,3,2,1]]
예제 2:

입력: n = 2
출력: [[1,2], [2,1]]
예제 3:

입력: n = 3
출력: [[1,2,3], [3,2,1]]
제약 조건:

1 <= n <= 10
*/
