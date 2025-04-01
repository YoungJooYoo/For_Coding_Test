class Solution 
{
public:
    long long mostPoints(const vector<vector<int>>& questions) const 
    {
        const size_t n = questions.size();
        vector<long long> dp(n + 1, 0);
        assert(n >= MIN_LENGTH && n <= MAX_LENGTH);
        
        for (int i = n - 1; i >= 0; --i) 
        {
            const int points = questions[i][0];
            const int brainpower = questions[i][1];
            assert(questions[i].size() == QUESTION_SIZE);
            assert(points >= MIN_VALUE && points <= MAX_VALUE);
            assert(brainpower >= MIN_VALUE && brainpower <= MAX_VALUE);
            const int nextIndex = i + brainpower + 1;
            const long long optionSolve = points + (nextIndex < dp.size() ? dp[nextIndex] : 0);
            const long long optionSkip = dp[i + 1]; // 질문 i를 건너뛰는 경우
            dp[i] = max(optionSolve, optionSkip);
        }
        
        return dp[0];
    }

private:
    enum {
        MIN_LENGTH = 1,
        MAX_LENGTH = 100000,
        MIN_VALUE = 1,
        MAX_VALUE = 100000,
        QUESTION_SIZE = 2,
    };
};


// https://leetcode.com/problems/solving-questions-with-brainpower/description/
/*

---

**2140. Brainpower를 사용하여 문제 해결하기**

**난이도:** 중간

**문제 설명:**  
0-indexed 2차원 정수 배열 **questions**가 주어지며, 각 `questions[i] = [pointsi, brainpoweri]`입니다.

이 배열은 시험 문제들을 나타냅니다. 문제는 0번부터 순서대로 처리해야 하며, 각 문제를 풀지 건너뛸지 결정해야 합니다.  
- 문제 i를 풀면 `pointsi` 점수를 얻지만, 그 후에 바로 이어지는 `brainpoweri` 개의 문제는 풀 수 없게 됩니다.
- 문제 i를 건너뛰면 바로 다음 문제부터 다시 결정할 수 있습니다.

예를 들어, `questions = [[3, 2], [4, 3], [4, 4], [2, 5]]`의 경우:
- 문제 0을 풀면 3점을 얻지만, 문제 1과 문제 2는 풀 수 없습니다.
- 반면, 문제 0을 건너뛰고 문제 1을 풀면 4점을 얻지만, 문제 2와 문제 3은 풀 수 없습니다.

시험에서 얻을 수 있는 최대 점수를 반환하세요.

---

**예제 1:**

- **입력:** questions = [[3,2],[4,3],[4,4],[2,5]]
- **출력:** 5
- **설명:**  
  최대 점수는 문제 0과 문제 3을 풀어 얻을 수 있습니다.
  - 문제 0 풀기: 3점 획득, 다음 2문제(문제 1과 2)는 풀 수 없음.
  - 문제 3 풀기: 2점 획득.
  총 점수: 3 + 2 = 5. 5점 이상 얻을 수 있는 다른 방법은 없습니다.

---

**예제 2:**

- **입력:** questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
- **출력:** 7
- **설명:**  
  최대 점수는 문제 1과 문제 4를 풀어 얻을 수 있습니다.
  - 문제 0 건너뛰기.
  - 문제 1 풀기: 2점 획득, 다음 2문제(문제 2와 3)는 풀 수 없음.
  - 문제 4 풀기: 5점 획득.
  총 점수: 2 + 5 = 7. 7점 이상 얻을 수 있는 다른 방법은 없습니다.

---

**제약 조건:**

- 1 <= questions.length <= 10^5  
- questions[i].length == 2  
- 1 <= pointsi, brainpoweri <= 10^5

---
*/
